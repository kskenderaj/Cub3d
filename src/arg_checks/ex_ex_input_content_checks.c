/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_ex_input_content_checks.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:52:20 by mimacdou          #+#    #+#             */
/*   Updated: 2026/06/09 15:52:21 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../cub3d.h"

void	invaild_rgb(int fd, char *line, int flag)
{
	if (flag == 0)
		(close(fd), free(line), invaild_arg("Floor RGB invalid"));
	else
		(close(fd), free(line), invaild_arg("Ceiling RGB invalid"));
}

bool	check_first_two_lines(char *texture)
{
	int		fd;
	char	*line;

	fd = open(texture, O_RDWR);
	line = get_next_line(fd);
	if (!line || ft_strncmp(line, "/* XPM */", 10) != 0)
		return (free(line), close(fd), false);
	(free(line), line = get_next_line(fd));
	if (!line || ft_strncmp(line, "static char *dummy[]={", 23) != 0)
		return (free(line), close(fd), false);
	return (free(line), close(fd), true);
}

static void	num_of_digits_check(int fd, char *line, int flag)
{
	int	i;
	int	len;
	int	num;

	i = 0;
	num = 0;
	len = ft_strlen(line);
	if (flag == 0)
		coloured_write("- Floor RGB vaild: ", YEL, 1);
	else
		coloured_write("- Ceiling RGB vaild: ", YEL, 1);
	while (i++ < len)
		if (ft_isdigit(line[i]) == 1)
			num++;
	if (num > 9 || num < 3)
		invaild_rgb(fd, line, flag);
	i = 0;
	num = 0;
	while (i++ < len)
		if (line[i] == ',')
			num++;
	if (num != 2)
		invaild_rgb(fd, line, flag);
	additional_rgb_checks(fd, line, flag);
	coloured_write("Passed\n", BHGRN, 1);
}

static void	c_f_rgb_checks(int fd, char *line, int flag)
{
	if (flag == 0)
	{
		coloured_write("- Floor RGB present: ", YEL, 1);
		if (ft_strlen(line) == 1 || ft_strlen(line) == 2)
			(close(fd), free(line), invaild_arg(\
"Floor RGB missing or misaligned"));
		coloured_write("Passed\n", BHGRN, 1);
		num_of_digits_check(fd, line, flag);
	}
	else
	{
		coloured_write("- Ceiling RGB present: ", YEL, 1);
		if (ft_strlen(line) == 1 || ft_strlen(line) == 2)
			(close(fd), free(line), invaild_arg(\
"Ceiling RGB missing or misaligned"));
		coloured_write("Passed\n", BHGRN, 1);
		num_of_digits_check(fd, line, flag);
	}
}

void	f_and_c_checks(char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDWR);
	line = get_next_line(fd);
	while (!ft_strchr(line, 'F') && line)
		(free(line), line = get_next_line(fd));
	coloured_write("- Floor identifier present: ", YEL, 1);
	if (!line)
		invaild_arg("Floor identifier missing");
	coloured_write("Passed\n", BHGRN, 1);
	c_f_rgb_checks(fd, line, 0);
	while (!ft_strchr(line, 'C') && line)
		(free(line), line = get_next_line(fd));
	coloured_write("- Ceiling identifier present: ", YEL, 1);
	if (!line)
		invaild_arg("Ceiling identifier missing");
	coloured_write("Passed\n", BHGRN, 1);
	c_f_rgb_checks(fd, line, 1);
	(close(fd), free(line));
}
