/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klejdi <klejdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:53:23 by mimacdou          #+#    #+#             */
/*   Updated: 2026/07/03 18:21:12 by klejdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void init_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init(800, 600, "cub3D", false);
	if (!game->mlx.mlx)
		exit(1);
	game->mlx.img = mlx_new_image(game->mlx.mlx, 800, 600);
	if (!game->mlx.img)
		exit(1);
	mlx_image_to_window(game->mlx.mlx, game->mlx.img, 0, 0);
	init_hooks(game);
}
