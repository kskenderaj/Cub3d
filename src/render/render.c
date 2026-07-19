/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:53:31 by mimacdou          #+#    #+#             */
/*   Updated: 2026/07/19 02:33:45 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

static int	get_rgb(char **color)
{
	return (rgb_to_int(ft_atoi(color[0]), ft_atoi(color[1]), \
ft_atoi(color[2])));
}

static void	draw_ceiling_floor(\
t_game *game, int x, int draw_start, int draw_end)
{
	int	y;

	y = 0;
	while (y < draw_start)
		put_pixel(game, x, y++, get_rgb(game->ceiling_color));
	y = draw_end;
	while (y < 600)
		put_pixel(game, x, y++, get_rgb(game->floor_color));
}

static void	draw_wall(t_game *game, int x, int draw_start, t_ray *ray)
{
	int	y;
	int	line_height;
	int	color;

	line_height = (int)(600 / ray->perp_dist);
	y = draw_start;
	while (y < draw_start + line_height && y < 600)
	{
		color = get_wall_color(game, ray, (y - draw_start) * 64 / line_height);
		put_pixel(game, x, y, color);
		y++;
	}
}

static void	draw_column(t_game *game, int x, t_ray *ray)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(600 / ray->perp_dist);
	draw_start = (600 - line_height) / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = draw_start + line_height;
	if (draw_end > 600)
		draw_end = 600;
	draw_ceiling_floor(game, x, draw_start, draw_end);
	draw_wall(game, x, draw_start, ray);
}

void	render_frame(void *param)
{
	t_game		*game;
	int			x;
	t_ray		ray;
	static int	frame_count = 0;

	fprintf(stderr, "frame %d\n", frame_count++);
	game = (t_game *)param;
	x = 0;
	while (x < 800)
	{
		cast_ray(game, &ray, x);
		draw_column(game, x, &ray);
		x++;
	}
}
