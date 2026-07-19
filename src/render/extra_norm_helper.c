/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_norm_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 09:04:09 by mimacdou          #+#    #+#             */
/*   Updated: 2026/07/19 09:04:33 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_tex_y(int y, mlx_image_t *image)
{
	int	tex_y;

	tex_y = (int)((y * (int)image->height) / 64);
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= (int)image->height)
		tex_y = (int)image->height - 1;
	return (tex_y);
}

int	get_tex_pixel(mlx_image_t *image, int tex_x, int tex_y)
{
	uint32_t	*pixels;

	pixels = (uint32_t *)image->pixels;
	return (pixels[tex_y * image->width + tex_x]);
}
