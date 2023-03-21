/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:27:23 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/21 11:19:45 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return ((void)ft_printf("wrong number of arguments !\n"), 1);
	if (check_directory(argv[1]) || check_filename(argv[1]))
		return (1);
	ber_to_array(argv[1], &game);
	init_my_window(&game);
	mlx_string_put(game.mlx_ptr, game.win_ptr, 300, 300, 0X00FFFF, "so_long");
	mlx_destroy_window(game.mlx_ptr, game.win_ptr);
	mlx_loop(game.mlx_ptr);
	free(game.mlx_ptr);
}
