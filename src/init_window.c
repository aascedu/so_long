/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:32:14 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/21 11:21:51 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_my_window(t_game* game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_error_launched("mlx_init", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1280, 720, "so_long");
	if (game->win_ptr == NULL)
		ft_error_launched("mlx_new_window", game);
}