/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:42:17 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/24 15:55:34 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->pos_y - 1][game->pos_x] == '1')
		return ;
	else if (game->map[game->pos_y - 1][game->pos_x] == 'C')
	{
		game->map[game->pos_y - 1][game->pos_x] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_y--;
		game->nb_collected++;
		game->steps++;
		ft_printf("number of steps : %d\n", game->steps);
		display_map(game);
	}
	else if (game->map[game->pos_y - 1][game->pos_x] == '0' \
	|| game->map[game->pos_y - 1][game->pos_x] == 'E')
	{
		game->map[game->pos_y - 1][game->pos_x] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_y--;
		game->steps++;
		ft_printf("number of steps : %d\n", game->steps);
		display_map(game);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x + 1] == '1')
		return ;
	else if (game->map[game->pos_y][game->pos_x + 1] == 'C')
	{
		game->map[game->pos_y][game->pos_x + 1] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_x++;
		game->nb_collected++;
		game->steps++;
		ft_printf("number of steps : %d\n", game->steps);
		display_map(game);
	}
	else if (game->map[game->pos_y][game->pos_x + 1] == '0' \
	|| game->map[game->pos_y][game->pos_x + 1] == 'E')
	{
		game->map[game->pos_y][game->pos_x + 1] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_x++;
		game->steps++;
		ft_printf("number of steps : %d\n", game->steps);
		display_map(game);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x - 1] == '1')
		return ;
	else if (game->map[game->pos_y][game->pos_x - 1] == 'C')
	{
		game->map[game->pos_y][game->pos_x - 1] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_x--;
		game->nb_collected++;
		game->steps++;
		ft_printf("number of steps : %d\n", game->steps);
		display_map(game);
	}
	else if (game->map[game->pos_y][game->pos_x - 1] == '0' \
	|| game->map[game->pos_y][game->pos_x - 1] == 'E')
	{
		game->map[game->pos_y][game->pos_x - 1] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_x--;
		game->steps++;
		ft_printf("number of steps : %d\n", game->steps);
		display_map(game);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->pos_y + 1][game->pos_x] == '1')
		return ;
	else if (game->map[game->pos_y + 1][game->pos_x] == 'C')
	{
		game->map[game->pos_y + 1][game->pos_x] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_y++;
		game->nb_collected++;
		game->steps++;
		ft_printf("number of steps : %d\n", game->steps);
		display_map(game);
	}
	else if (game->map[game->pos_y + 1][game->pos_x] == '0' \
	|| game->map[game->pos_y + 1][game->pos_x] == 'E')
	{
		game->map[game->pos_y + 1][game->pos_x] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_y++;
		game->steps++;
		ft_printf("number of steps : %d\n", game->steps);
		display_map(game);
	}
}
