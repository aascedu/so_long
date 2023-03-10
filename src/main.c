/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:27:23 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/09 13:40:43 by arthurasced      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	window_ptr = mlx_new_window(mlx_ptr, 600, 600, "so_long");
	mlx_string_put(mlx_ptr, window_ptr, 300, 300, 0X00FFFF, "THEA J'AI ECRIT UN TEXT WESH");
	mlx_loop(mlx_ptr);
}