/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:27:23 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/16 09:44:55 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || check_directory(argv[1]) || check_filename(argv[1]))
		return (1);
	ber_to_array(argv[1], &game);
	free_array(game.map);
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return (1);
	game.win_ptr = mlx_new_window(game.mlx_ptr, 600, 600, "so_long");
	mlx_string_put(game.mlx_ptr, game.win_ptr, 300, 300, 0X00FFFF, "so_long");
	mlx_loop(game.mlx_ptr);
}
