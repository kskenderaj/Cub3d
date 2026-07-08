/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klejdi <klejdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:00:00 by klejdi             #+#    #+#             */
/*   Updated: 2026/07/03 18:00:00 by klejdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

extern void handle_movement(t_game *game);

static void rotate_player(t_game *game, int direction)
{
    double old_dir_x;
    double old_plane_x;
    double angle;

    angle = direction * 0.05;
    old_dir_x = game->player.dir_x;
    game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y * sin(angle);
    game->player.dir_y = old_dir_x * sin(angle) + game->player.dir_y * cos(angle);
    old_plane_x = game->player.plane_x;
    game->player.plane_x = game->player.plane_x * cos(angle) - game->player.plane_y * sin(angle);
    game->player.plane_y = old_plane_x * sin(angle) + game->player.plane_y * cos(angle);
}

static void handle_rotation(t_game *game)
{
    if (mlx_is_key_down(game->mlx.mlx, KEY_LEFT))
        rotate_player(game, 1);
    if (mlx_is_key_down(game->mlx.mlx, KEY_RIGHT))
        rotate_player(game, -1);
}

static void handle_exit(t_game *game)
{
    if (mlx_is_key_down(game->mlx.mlx, KEY_ESC))
        mlx_close_window(game->mlx.mlx);
}

void game_loop(void *param)
{
    t_game *game;

    game = (t_game *)param;
    handle_movement(game);
    handle_rotation(game);
    handle_exit(game);
    render_frame(game);
}
