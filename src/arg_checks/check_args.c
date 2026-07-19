/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:52:06 by mimacdou          #+#    #+#             */
/*   Updated: 2026/07/19 02:22:25 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	print_extras(int flag)
{
	if (flag == 0)
	{
		coloured_write("-------------------------------------\n", BHYEL, 1);
		coloured_write("      STARTING INPUT CHECKS      \n", BHYEL, 1);
		coloured_write("-------------------------------------\n", BHYEL, 1);
		coloured_write("- Argument Present Check: ", YEL, 1);
	}
	if (flag == 1)
	{
		coloured_write("-------------------------------------\n", BHGRN, 1);
		coloured_write("        MAP PASSED ALL CHECKS     \n\n", BHGRN, 1);
		coloured_write("         -BEGINING PARSING-       \n", BHBLU, 1);
		coloured_write("-------------------------------------\n", BHGRN, 1);
	}
}

void	invaild_arg(char *str)
{
	coloured_write("Error\n", BHRED, 2);
	coloured_write(str, BHRED, 2);
	write(1, "\n", 1);
	exit(1);
}

static bool	extension_check(char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	str_len--;
	if (str[str_len--] != 'b')
		return (false);
	if (str[str_len--] != 'u')
		return (false);
	if (str[str_len--] != 'c')
		return (false);
	if (str[str_len] != '.')
		return (false);
	return (true);
}

bool	exists_check(char *str)
{
	int	fd;

	fd = open(str, O_RDWR);
	if (fd < 0 || fd > 1024)
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

void	check_args(int ac, char **av)
{
	print_extras(0);
	if (ac < 2)
		invaild_arg("Missing arguemnts");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- Multiple Argument Check: ", YEL, 1);
	if (ac > 2)
		invaild_arg("Too many arguments");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- Is Argument Empty: ", YEL, 1);
	if (ft_strlen(av[1]) == 0)
		invaild_arg("Empty argument");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- Vaild Argument Extension: ", YEL, 1);
	if (!extension_check(av[1]))
		invaild_arg("File has invalid extension");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- Does File Exist: ", YEL, 1);
	if (!exists_check(av[1]))
		invaild_arg(strerror(errno));
	coloured_write("Passed\n", BHGRN, 1);
	input_content_checks(av[1]);
	print_extras(1);
}
