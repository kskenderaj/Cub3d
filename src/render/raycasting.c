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

#include "../../cub3D.h"
#include <math.h>

static void init_ray_dir(t_game *game, double *ray_dir_x,
                         double *ray_dir_y, int x)
{
    double camera_x;

    camera_x = 2.0 * x / 800.0 - 1.0;
    *ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
    *ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;
}

static void init_step(double ray_dir_x, double ray_dir_y,
                      double player_x, double player_y, t_ray *ray)
{
    ray->dir_x = ray_dir_x;
    ray->dir_y = ray_dir_y;
    ray->start_x = player_x;
    ray->start_y = player_y;
}

static void dda_loop(t_game *game, t_ray *ray, double *side_dist_x,
                     double *side_dist_y, int *map_x, int *map_y)
{
    int hit;
    int side;
    int mh;

    hit = 0;
    mh = store_house(999);
    while (!hit)
    {
        if (*side_dist_x < *side_dist_y)
        {
            *side_dist_x += fabs(1.0 / ray->dir_x);
            *map_x += (*map_x < game->player.x) ? 1 : -1;
            side = 0;
        }
        else
        {
            *side_dist_y += fabs(1.0 / ray->dir_y);
            *map_y += (*map_y < game->player.y) ? 1 : -1;
            side = 1;
        }
        if (*map_y >= 0 && *map_y < mh && *map_x >= 0 && *map_x < (int)ft_strlen(game->map[*map_y]))
            if (game->map[*map_y][*map_x] == '1')
                hit = 1;
        ray->side = side;
    }
}

void cast_ray(t_game *game, t_ray *ray, int x)
{
    int map_x;
    int map_y;
    double side_dist_x;
    double side_dist_y;

    map_x = (int)game->player.x;
    map_y = (int)game->player.y;
    init_ray_dir(game, &ray->dir_x, &ray->dir_y, x);
    init_step(ray->dir_x, ray->dir_y, game->player.x, game->player.y, ray);
    side_dist_x = fabs((game->player.x - map_x) / ray->dir_x);
    side_dist_y = fabs((game->player.y - map_y) / ray->dir_y);
    dda_loop(game, ray, &side_dist_x, &side_dist_y, &map_x, &map_y);
    ray->perp_dist = (ray->side == 0) ? fabs((map_x - game->player.x) / ray->dir_x) : fabs((map_y - game->player.y) / ray->dir_y);
    if (ray->perp_dist < 0.1)
        ray->perp_dist = 0.1;
}
