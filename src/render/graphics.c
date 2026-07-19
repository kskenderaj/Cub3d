/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assistant <assistant@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 00:00:00 by assistant         #+#    #+#             */
/*   Updated: 2026/07/03 00:00:00 by assistant        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	if (x >= 0 && x < 800 && y >= 0 && y < 600)
		mlx_put_pixel(game->mlx.img, x, y, color);
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}

int	get_wall_color(t_game *game, t_ray *ray, int y)
{
	(void)game;
	(void)ray;
	(void)y;
	return (0xFF0000FF);
}
