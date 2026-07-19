/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   janitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:52:52 by mimacdou          #+#    #+#             */
/*   Updated: 2026/07/19 02:22:39 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_matrix(char **matrix, int height)
{
	int	n;

	n = 0;
	while (n != height)
	{
		free(matrix[n]);
		n++;
	}
	free(matrix);
}

void	free_textures(t_game *game, enum e_tex flag)
{
	t_texture	*tmp;

	tmp = &game->textures[flag];
	if (tmp->img)
		mlx_delete_image(game->mlx.mlx, tmp->img);
	free(tmp->addr);
}

void	free_game(t_game *game)
{
	free_textures(game, T_NORTH);
	free_textures(game, T_SOUTH);
	free_textures(game, T_EAST);
	free_textures(game, T_WEST);
	if (game->mlx.img)
		mlx_delete_image(game->mlx.mlx, game->mlx.img);
	if (game->mlx.mlx)
		mlx_terminate(game->mlx.mlx);
	free_matrix(game->map, store_house(999));
	free_matrix(game->floor_color, 3);
	free_matrix(game->ceiling_color, 3);
}
