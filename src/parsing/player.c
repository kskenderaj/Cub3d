/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assistant <assistant@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 00:00:00 by assistant         #+#    #+#             */
/*   Updated: 2026/07/03 00:00:00 by assistant        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void find_player_position(t_game *game, char **map)
{
    int i;
    int h;
    int mh;

    i = 0;
    h = 0;
    mh = store_house(999);
    while (h < mh)
    {
        while (map[h][i])
        {
            if (map[h][i] == 'N' || map[h][i] == 'S' || map[h][i] == 'W' || map[h][i] == 'E')
            {
                game->player.x = i + 0.5;
                game->player.y = h + 0.5;
                return;
            }
            i++;
        }
        i = 0;
        h++;
    }
}

static void set_direction(t_game *game, char dir)
{
    if (dir == 'N')
    {
        game->player.dir_x = 0;
        game->player.dir_y = -1;
    }
    else if (dir == 'S')
    {
        game->player.dir_x = 0;
        game->player.dir_y = 1;
    }
    else if (dir == 'E')
    {
        game->player.dir_x = 1;
        game->player.dir_y = 0;
    }
    else if (dir == 'W')
    {
        game->player.dir_x = -1;
        game->player.dir_y = 0;
    }
}

static void init_camera_plane(t_game *game)
{
    if (game->player.dir_x == 0)
    {
        game->player.plane_x = game->player.dir_y * 0.66;
        game->player.plane_y = 0;
    }
    else
    {
        game->player.plane_x = 0;
        game->player.plane_y = game->player.dir_x * 0.66;
    }
}

void init_player(t_game *game)
{
    find_player_position(game, game->map);
    set_direction(game, game->player.starting_direction);
    init_camera_plane(game);
}
