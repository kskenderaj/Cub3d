/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:53:12 by mimacdou          #+#    #+#             */
/*   Updated: 2026/07/19 02:37:18 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static	int	is_point_walkable(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= store_house(999))
		return (0);
	if (map_x < 0 || map_x >= (int)ft_strlen(game->map[map_y]))
		return (0);
	if (game->map[map_y][map_x] == '1')
		return (0);
	return (1);
}

static int	is_walkable(t_game *game, double x, double y)
{
	if (!is_point_walkable(game, x - 0.2, y - 0.2))
		return (0);
	if (!is_point_walkable(game, x + 0.2, y - 0.2))
		return (0);
	if (!is_point_walkable(game, x - 0.2, y + 0.2))
		return (0);
	if (!is_point_walkable(game, x + 0.2, y + 0.2))
		return (0);
	return (1);
}

static void	move_player(t_game *game, double move_x, double move_y)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + move_x;
	new_y = game->player.y + move_y;
	if (is_walkable(game, new_x, game->player.y))
		game->player.x = new_x;
	if (is_walkable(game, game->player.x, new_y))
		game->player.y = new_y;
}

void	handle_movement(t_game *game)
{
	if (mlx_is_key_down(game->mlx.mlx, KEY_W))
		move_player(\
game, game->player.dir_x * 0.1, game->player.dir_y * 0.1);
	if (mlx_is_key_down(game->mlx.mlx, KEY_S))
		move_player(\
game, -game->player.dir_x * 0.1, -game->player.dir_y * 0.1);
	if (mlx_is_key_down(game->mlx.mlx, KEY_A))
		move_player(\
game, -game->player.plane_x * 0.1, -game->player.plane_y * 0.1);
	if (mlx_is_key_down(game->mlx.mlx, KEY_D))
		move_player(\
game, game->player.plane_x * 0.1, game->player.plane_y * 0.1);
}

void	init_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx.mlx, (void *)&game_loop, game);
}
