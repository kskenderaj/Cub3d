/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_map_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:52:31 by mimacdou          #+#    #+#             */
/*   Updated: 2026/07/19 02:22:32 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	get_player_coords(char **matrix, int height, int flag)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	while (!ft_strchr(matrix[y], 'N') && !ft_strchr(matrix[y], \
'E') && !ft_strchr(matrix[y], 'S') && !ft_strchr(matrix[y], 'W') && y <= height)
		y++;
	while (matrix[y][x] && matrix[y][x] != 'N' && matrix[y][x] != 'E' \
&& matrix[y][x] != 'S' && matrix[y][x] != 'W')
		x++;
	if (flag == 0)
		return (y);
	return (x);
}

void	fill(char **matrix, int y, int x, int height)
{
	if (y < 0 || x < 0 || y >= height || !matrix[y] || \
!matrix[y][x] || matrix[y][x] == ' ')
	{
		flood_status(1);
		return ;
	}
	if (matrix[y][x] == 'F' || matrix[y][x] == '1')
		return ;
	matrix[y][x] = 'F';
	fill(matrix, y + 1, x, height);
	fill(matrix, y - 1, x, height);
	fill(matrix, y, x + 1, height);
	fill(matrix, y, x - 1, height);
	fill(matrix, y + 1, x + 1, height);
	fill(matrix, y - 1, x - 1, height);
	fill(matrix, y -1, x + 1, height);
	fill(matrix, y + 1, x - 1, height);
}

bool	flood_matrix(char **matrix, int height)
{
	int	x;
	int	y;

	y = get_player_coords(matrix, height, 0);
	x = get_player_coords(matrix, height, 1);
	fill(matrix, y, x, height);
	if (flood_status(0) == false)
		return (true);
	return (false);
}
