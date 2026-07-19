/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:52:59 by mimacdou          #+#    #+#             */
/*   Updated: 2026/07/19 09:05:06 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	get_starting_direction(char **map)
{
	int	i;
	int	h;
	int	mh;

	i = 0;
	h = 1;
	mh = store_house(999);
	while (h < mh)
	{
		while (map[h][i])
		{
			if (\
map[h][i] == 'N' || map[h][i] == 'S' || map[h][i] == 'W' || map[h][i] == 'E')
				return (map[h][i]);
			i++;
		}
		i = 0;
		h++;
	}
	return ('i');
}

void	init_texture(t_game *game, enum e_tex flag, char *line)
{
	t_texture	*tmp;

	tmp = &game->textures[flag];
	tmp->addr = ft_strdup(ft_strchr(line, 'M'));
}

void	parser(t_game *game, char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDWR);
	line = cycle_gnl(fd, "NO");
	init_texture(game, T_NORTH, line);
	(free(line), line = cycle_gnl(fd, "SO"), init_texture(game, T_SOUTH, line));
	(free(line), line = cycle_gnl(fd, "WE"), init_texture(game, T_WEST, line));
	(free(line), line = cycle_gnl(fd, "EA"), init_texture(game, T_EAST, line));
	(free(line), line = cycle_gnl(fd, "F"));
	game->floor_color = ft_split(ft_strchr(line, 'F') + 1, ',');
	(free(line), line = cycle_gnl(fd, "C"));
	game->ceiling_color = ft_split(ft_strchr(line, 'C') + 1, ',');
	(free(line), line = cycle_gnl(fd, "1"));
	game->map = make_floodfill_matrix(fd, line, map_file);
	game->player.starting_direction = get_starting_direction(game->map);
}
