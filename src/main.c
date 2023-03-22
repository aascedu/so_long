/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:27:23 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/22 14:34:18 by aascedu          ###   ########lyon.fr   */
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
	create_image(&game);
	display_map(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
