/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assistant <assistant@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 00:00:00 by assistant         #+#    #+#             */
/*   Updated: 2026/07/03 00:00:00 by assistant        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

static void	init_ray_dir(t_game *game, double *ray_dir_x,
		double *ray_dir_y, int x)
{
	double	camera_x;

	camera_x = 2.0 * x / 800.0 - 1.0;
	*ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	*ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;
	if (*ray_dir_x == 0)
		*ray_dir_x = 1e-9;
	if (*ray_dir_y == 0)
		*ray_dir_y = 1e-9;
}

static void	init_step(t_game *game, t_ray *ray)
{
	ray->dir_x = ray->dir_x;
	ray->dir_y = ray->dir_y;
	ray->start_x = game->player.x;
	ray->start_y = game->player.y;
	if (ray->dir_x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->dir_y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}

static void	init_side_dists(t_game *game, t_ray *ray,
			double *side_dist_x, double *side_dist_y)
{
	if (ray->dir_x < 0)
		*side_dist_x = (game->player.x - ray->map_x) * fabs(1.0 / ray->dir_x);
	else
		*side_dist_x = (ray->map_x + 1.0 - game->player.x)
			* fabs(1.0 / ray->dir_x);
	if (ray->dir_y < 0)
		*side_dist_y = (game->player.y - ray->map_y) * fabs(1.0 / ray->dir_y);
	else
		*side_dist_y = (ray->map_y + 1.0 - game->player.y)
			* fabs(1.0 / ray->dir_y);
}

static void	dda_loop(t_game *game, t_ray *ray,
			double *side_dist_x, double *side_dist_y)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (*side_dist_x < *side_dist_y)
		{
			*side_dist_x += fabs(1.0 / ray->dir_x);
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			*side_dist_y += fabs(1.0 / ray->dir_y);
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y >= 0 && ray->map_y < store_house(999)
			&& ray->map_x >= 0
			&& ray->map_x < (int)ft_strlen(game->map[ray->map_y]))
			if (game->map[ray->map_y][ray->map_x] == '1')
				hit = 1;
	}
}

void	cast_ray(t_game *game, t_ray *ray, int x)
{
	double	side_dist_x;
	double	side_dist_y;
	double	step_correction_x;
	double	step_correction_y;

	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	init_ray_dir(game, &ray->dir_x, &ray->dir_y, x);
	init_step(game, ray);
	init_side_dists(game, ray, &side_dist_x, &side_dist_y);
	dda_loop(game, ray, &side_dist_x, &side_dist_y);
	step_correction_x = (1.0 - ray->step_x) / 2.0;
	step_correction_y = (1.0 - ray->step_y) / 2.0;
	if (ray->side == 0)
		ray->perp_dist = (ray->map_x - game->player.x + step_correction_x)
			/ ray->dir_x;
	else
		ray->perp_dist = (ray->map_y - game->player.y + step_correction_y)
			/ ray->dir_y;
	if (ray->perp_dist < 0.1)
		ray->perp_dist = 0.1;
}
