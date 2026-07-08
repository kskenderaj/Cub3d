/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_content_checks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:52:37 by mimacdou          #+#    #+#             */
/*   Updated: 2026/06/09 15:52:38 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../cub3d.h"

static bool	texture_checks_two(char *map, int flag)
{
	int		fd;
	char	*line;
	char	*d_line;

	fd = open(map, O_RDWR);
	line = cycle_gnl(fd, "WE");
	if (!line)
		return (close(fd), false);
	d_line = ft_strchr(line, 'W');
	if (flag == 2)
		if (d_line[0] == 'W' && d_line[1] == 'E')
			return (free(line), close(fd), true);
	(free(line), line = cycle_gnl(fd, "EA"));
	if (!line)
		return (close(fd), false);
	d_line = ft_strchr(line, 'E');
	if (flag == 3)
		if (d_line[0] == 'E' && d_line[1] == 'A')
			return (free(line), close(fd), true);
	return (free(line), close(fd), false);
}

static bool	texture_checks(char *map, int flag)
{
	int		fd;
	char	*line;
	char	*d_line;

	fd = open(map, O_RDWR);
	line = cycle_gnl(fd, "NO");
	if (!line)
		return (close(fd), false);
	d_line = ft_strchr(line, 'N');
	if (flag == 0)
		if (d_line[0] == 'N' && d_line[1] == 'O')
			return (free(line), close(fd), true);
	(free(line), line = cycle_gnl(fd, "SO"));
	if (!line)
		return (close(fd), false);
	d_line = ft_strchr(line, 'S');
	if (flag == 1)
		if (d_line[0] == 'S' && d_line[1] == 'O')
			return (free(line), close(fd), true);
	return (free(line), close(fd), false);
}

static bool	texture_exist(char *map, int flag)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDWR);
	line = cycle_gnl(fd, "NO");
	if (flag == 0)
		if (exists_check(ft_strchr(line, 'M')))
			return (free(line), close(fd), true);
	(free(line), line = cycle_gnl(fd, "SO"));
	if (flag == 1)
		if (exists_check(ft_strchr(line, 'M')))
			return (free(line), close(fd), true);
	(free(line), line = cycle_gnl(fd, "WE"));
	if (flag == 2)
		if (exists_check(ft_strchr(line, 'M')))
			return (free(line), close(fd), true);
	(free(line), line = cycle_gnl(fd, "EA"));
	if (flag == 3)
		if (exists_check(ft_strchr(line, 'M')))
			return (free(line), close(fd), true);
	return (free(line), close(fd), false);
}

void	extra_content_checks(char *map)
{
	coloured_write("- NO Texture Exist: ", YEL, 1);
	if (!texture_exist(map, 0))
		invaild_arg(strerror(errno));
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- SO Texture Exist: ", YEL, 1);
	if (!texture_exist(map, 1))
		invaild_arg(strerror(errno));
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- WE Texture Exist: ", YEL, 1);
	if (!texture_exist(map, 2))
		invaild_arg(strerror(errno));
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- EA Texture Exist: ", YEL, 1);
	if (!texture_exist(map, 3))
		invaild_arg(strerror(errno));
	coloured_write("Passed\n", BHGRN, 1);
	input_content_extension_checks(map);
	extra_input_content_checks(map);
	actually_xpm_test(map);
	f_and_c_checks(map);
	map_checks(map);
}

void	input_content_checks(char *map)
{
	coloured_write("- Not Empty File: ", YEL, 1);
	if (!file_empty(map))
		invaild_arg("Map file empty");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- NO Texture Present: ", YEL, 1);
	if (!texture_checks(map, 0))
		invaild_arg("Texture NO absent");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- SO Texture Present: ", YEL, 1);
	if (!texture_checks(map, 1))
		invaild_arg("Texture SO absent");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- WE Texture Present: ", YEL, 1);
	if (!texture_checks_two(map, 2))
		invaild_arg("Texture WE absent");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- EA Texture Present: ", YEL, 1);
	if (!texture_checks_two(map, 3))
		invaild_arg("Texture EA absent");
	coloured_write("Passed\n", BHGRN, 1);
	extra_content_checks(map);
}
