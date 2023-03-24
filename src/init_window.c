/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:32:14 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/24 15:50:17 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_my_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_error_launched("mlx_init", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->size_x + 1) * 96, \
	(game->size_y + 1) * 96, "so_long");
	if (game->win_ptr == NULL)
		ft_error_launched("mlx_new_window", game);
}
