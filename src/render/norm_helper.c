/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 06:09:36 by mimacdou          #+#    #+#             */
/*   Updated: 2026/07/19 09:04:35 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_texture_path(char *path)
{
	char	*converted;
	size_t	len;

	len = ft_strlen(path);
	converted = malloc(len + 8);
	if (!converted)
		return (NULL);
	ft_strlcpy(converted, path, len + 8);
	if (len >= 4 && ft_strncmp(path + len - 4, ".xpm", 4) == 0)
		ft_strlcpy(converted + len - 4, ".xpm42", 8);
	return (converted);
}

void	load_one_texture(t_game *game, int index)
{
	t_texture	*texture;
	xpm_t		*xpm;
	char		*path;

	texture = &game->textures[index];
	if (!texture->addr)
		return ;
	path = get_texture_path(texture->addr);
	if (!path)
		return ;
	xpm = mlx_load_xpm42(path);
	if (!xpm)
	{
		free(path);
		return ;
	}
	free(path);
	fill_texture_data(game, texture, xpm);
	mlx_delete_xpm42(xpm);
}

void	fill_texture_data(t_game *game, t_texture *texture, xpm_t *xpm)
{
	texture->img = mlx_texture_to_image(game->mlx.mlx, &xpm->texture);
	texture->width = xpm->texture.width;
	texture->height = xpm->texture.height;
	texture->bits_per_pixel = xpm->texture.bytes_per_pixel * 8;
	texture->line_length = xpm->texture.width * xpm->texture.bytes_per_pixel;
	texture->endian = 0;
}

int	get_texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			return (T_WEST);
		return (T_EAST);
	}
	if (ray->dir_y < 0)
		return (T_NORTH);
	return (T_SOUTH);
}

int	get_tex_x(t_game *game, t_ray *ray, mlx_image_t *image)
{
	double	wall_pos;
	int		tex_x;

	if (ray->side == 0)
		wall_pos = game->player.y + ray->dir_y * ray->perp_dist;
	else
		wall_pos = game->player.x + ray->dir_x * ray->perp_dist;
	wall_pos -= floor(wall_pos);
	tex_x = (int)(wall_pos * (double)image->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= (int)image->width)
		tex_x = (int)image->width - 1;
	return (tex_x);
}
