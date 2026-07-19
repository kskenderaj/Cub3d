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

void	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		load_one_texture(game, i);
		i++;
	}
}

mlx_image_t	*get_texture_image(t_game *game, t_ray *ray)
{
	t_texture	*texture;
	int			texture_index;

	texture_index = get_texture_index(ray);
	texture = &game->textures[texture_index];
	if (!texture->img)
		return (NULL);
	return ((mlx_image_t *)texture->img);
}

int	get_wall_color(t_game *game, t_ray *ray, int y)
{
	mlx_image_t	*image;
	int			tex_x;
	int			tex_y;

	image = get_texture_image(game, ray);
	if (!image || !image->pixels || image->width <= 0 || image->height <= 0)
		return (0xFF0000FF);
	tex_x = get_tex_x(game, ray, image);
	tex_y = get_tex_y(y, image);
	return (get_tex_pixel(image, tex_x, tex_y));
}
