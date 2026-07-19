/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_input_content_checks.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:52:25 by mimacdou          #+#    #+#             */
/*   Updated: 2026/07/19 02:22:30 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static bool	extension_check(char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	str_len--;
	if (str[str_len--] != 'm')
		return (false);
	if (str[str_len--] != 'p')
		return (false);
	if (str[str_len--] != 'x')
		return (false);
	if (str[str_len] != '.')
		return (false);
	return (true);
}

bool	texture_not_empty(char *map, int flag)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDWR);
	line = cycle_gnl(fd, "NO");
	if (flag == 0)
		if (file_empty(ft_strchr(line, 'M')))
			return (free(line), close(fd), true);
	(free(line), line = cycle_gnl(fd, "SO"));
	if (flag == 1)
		if (file_empty(ft_strchr(line, 'M')))
			return (free(line), close(fd), true);
	(free(line), line = cycle_gnl(fd, "WE"));
	if (flag == 2)
		if (file_empty(ft_strchr(line, 'M')))
			return (free(line), close(fd), true);
	(free(line), line = cycle_gnl(fd, "EA"));
	if (flag == 3)
		if (file_empty(ft_strchr(line, 'M')))
			return (free(line), close(fd), true);
	return (free(line), close(fd), false);
}

void	extra_input_content_checks(char *map)
{
	coloured_write("- NO Not Empty: ", YEL, 1);
	if (!texture_not_empty(map, 0))
		invaild_arg("NO Texture empty");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- SO Not Empty: ", YEL, 1);
	if (!texture_not_empty(map, 1))
		invaild_arg("SO Texture empty");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- WE Not Empty: ", YEL, 1);
	if (!texture_not_empty(map, 2))
		invaild_arg("WE Texture empty");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- EA Not Empty: ", YEL, 1);
	if (!texture_not_empty(map, 3))
		invaild_arg("EA Texture empty");
	coloured_write("Passed\n", BHGRN, 1);
}

void	input_content_extension_checks(char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDWR);
	line = cycle_gnl(fd, "NO");
	coloured_write("- NO Texture Extension: ", YEL, 1);
	if (!extension_check(line))
		invaild_arg("NO texture has invalid extension");
	coloured_write("Passed\n", BHGRN, 1);
	(free(line), line = cycle_gnl(fd, "SO"));
	coloured_write("- SO Texture Extension: ", YEL, 1);
	if (!extension_check(line))
		invaild_arg("SO texture has invalid extension");
	coloured_write("Passed\n", BHGRN, 1);
	(free(line), line = cycle_gnl(fd, "WE"));
	coloured_write("- WE Texture Extension: ", YEL, 1);
	if (!extension_check(line))
		invaild_arg("WE texture has invalid extension");
	coloured_write("Passed\n", BHGRN, 1);
	(free(line), line = cycle_gnl(fd, "EA"));
	coloured_write("- EA Texture Extension: ", YEL, 1);
	if (!extension_check(line))
		invaild_arg("EA texture has invalid extension");
	coloured_write("Passed\n", BHGRN, 1);
	(close(fd), free(line));
}

void	actually_xpm_test(char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDWR);
	line = cycle_gnl(fd, "NO");
	coloured_write("- NO actually xpm: ", YEL, 1);
	if (!check_first_two_lines(ft_strchr(line, 'M')))
		(free(line), invaild_arg("NO texture is a false xpm file"));
	(coloured_write("Passed\n", BHGRN, 1), free(line), \
line = cycle_gnl(fd, "SO"));
	coloured_write("- SO actually xpm: ", YEL, 1);
	if (!check_first_two_lines(ft_strchr(line, 'M')))
		(free(line), invaild_arg("SO texture is a false xpm file"));
	(coloured_write("Passed\n", BHGRN, 1), free(line), \
line = cycle_gnl(fd, "WE"));
	coloured_write("- WE actually xpm: ", YEL, 1);
	if (!check_first_two_lines(ft_strchr(line, 'M')))
		(free(line), invaild_arg("WE texture is a false xpm file"));
	(coloured_write("Passed\n", BHGRN, 1), free(line), \
line = cycle_gnl(fd, "EA"));
	coloured_write("- EA actually xpm: ", YEL, 1);
	if (!check_first_two_lines(ft_strchr(line, 'M')))
		(free(line), invaild_arg("EA texture is a false xpm file"));
	(coloured_write("Passed\n", BHGRN, 1), free(line), close(fd));
}
