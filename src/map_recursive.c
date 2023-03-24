/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_recursive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:57:37 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/24 15:41:06 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_start_pos(t_game *game)
{
	game->pos_y = 0;
	while (game->map[game->pos_y])
	{
		game->pos_x = 0;
		while (game->map[game->pos_y][game->pos_x])
		{
			if (game->map[game->pos_y][game->pos_x] == 'P')
				return ;
			game->pos_x++;
		}
		game->pos_y++;
	}
}

void	find_exit_pos(t_game *game)
{
	game->exit_y = 0;
	while (game->map[game->exit_y])
	{
		game->exit_x = 0;
		while (game->map[game->exit_y][game->exit_x])
		{
			if (game->map[game->exit_y][game->exit_x] == 'E')
			{
				game->map[game->exit_y][game->exit_x] = '0';
				return ;
			}
			game->exit_x++;
		}
		game->exit_y++;
	}
}

void	map_recursive(t_game *game, int y, int x)
{
	if (game->map_copy[y][x - 1] != '1')
	{
		game->map_copy[y][x] = '1';
		map_recursive(game, y, x - 1);
	}
	if (game->map_copy[y][x + 1] != '1')
	{
		game->map_copy[y][x] = '1';
		map_recursive(game, y, x + 1);
	}
	if (game->map_copy[y - 1][x] != '1')
	{
		game->map_copy[y][x] = '1';
		map_recursive(game, y - 1, x);
	}
	if (game->map_copy[y + 1][x] != '1')
	{
		game->map_copy[y][x] = '1';
		map_recursive(game, y + 1, x);
	}
	game->map_copy[y][x] = '1';
}
