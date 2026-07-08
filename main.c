/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klejdi <klejdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:38:29 by mimacdou          #+#    #+#             */
/*   Updated: 2026/07/03 18:17:46 by klejdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_game game;

	check_args(ac, av);
	ft_memset(&game, 0, sizeof(t_game));
	parser(&game, av[1]);
	init_player(&game);
	init_mlx(&game);
	mlx_loop_hook(game.mlx.mlx, render_frame, &game);
	mlx_loop(game.mlx.mlx);
	free_game(&game);
	return (0);
}
