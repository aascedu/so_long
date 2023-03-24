/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:27:23 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/24 16:14:57 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(t_keycode keycode, t_game *game)
{
	if (keycode == 65307)
		destroy_image(game);
	if (keycode == 119 || keycode == 65362)
		move_up(game);
	if (keycode == 97 || keycode == 65361)
		move_left(game);
	if (keycode == 100 || keycode == 65363)
		move_right(game);
	if (keycode == 115 || keycode == 65364)
		move_down(game);
	return (0);
}

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
	game.steps = 0;
	mlx_key_hook(game.win_ptr, key_press, &game);
	mlx_hook(game.win_ptr, 17, 1L << 17, destroy_image, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
