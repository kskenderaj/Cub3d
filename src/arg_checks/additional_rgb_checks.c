/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_rgb_checks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:51:57 by mimacdou          #+#    #+#             */
/*   Updated: 2026/06/09 15:51:58 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../cub3d.h"

bool	file_empty(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDWR);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (free(line), true);
}

static bool	zeros_pos_check(char **octect, int flag)
{
	int	pos_uno;
	int	pos_dos;
	int	pos_tres;

	pos_uno = 0;
	pos_dos = 0;
	pos_tres = 0;
	if (octect[flag][0] == '0')
		pos_uno = 1;
	if (octect[flag][1] == '0')
		pos_dos = 1;
	if (octect[flag][2] == '0')
		pos_tres = 1;
	if (pos_uno == 1 && pos_dos == 1)
		return (false);
	if (pos_uno == 1 && pos_tres == 1)
		return (false);
	return (true);
}

static void	zeros_check(int fd, char *line, int flag, char **octect)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 0;
	j = 0;
	while (i <= 2)
	{
		while (octect[i][j])
		{
			if (octect[i][j] == '0')
				n++;
			j++;
		}
		if (n == 3)
			(free_matrix(octect, 3), invaild_rgb(fd, line, flag));
		else if (n == 2)
			if (!zeros_pos_check(octect, i))
				(free_matrix(octect, 3), invaild_rgb(fd, line, flag));
		j = 0;
		n = 0;
		i++;
	}
}

void	additional_rgb_checks(int fd, char *line, int flag)
{
	char	**octect;
	char	*id_pos;
	int		num;
	int		i;

	if (flag == 0)
		id_pos = ft_strchr(line, 'F');
	else
		id_pos = ft_strchr(line, 'C');
	octect = ft_split(id_pos + 1, ',');
	i = 0;
	num = 0;
	while (i <= 2)
	{
		if (!octect && i == 0)
			(free(octect), invaild_rgb(fd, line, flag));
		if (!octect[i])
			(free_matrix(octect, 3), invaild_rgb(fd, line, flag));
		num = atoi(octect[i]);
		if (num > 255 || num < 0)
			(free_matrix(octect, 3), invaild_rgb(fd, line, flag));
		i++;
	}
	(zeros_check(fd, line, flag, octect), free_matrix(octect, 3));
}
