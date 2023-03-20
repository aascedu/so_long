/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:49:55 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/20 13:24:10 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(t_game *game)
{
	int	x;
	int	y;

	find_start_pos(game);
	map_recursive(game, game->pos_x, game->pos_y);
	y = 0;
	while (game->map_copy[y])
	{
		x = 0;
		while (game->map_copy[y][x])
		{
			if (game->map_copy[y][x] == 'C' || game->map_copy[y][x] == 'E')
			{
				free_array(game->map_copy);
				ft_error_launched("unsolvable map", game);
			}
			x++;
		}
		y++;
	}
}

void	is_rectangle(t_game *game)
{
	int	prev_len;

	game->pos_x = 0;
	while (game->map[0][game->pos_x])
		game->pos_x++;
	prev_len = game->pos_x;
	game->pos_y = 1;
	while (game->map[game->pos_y])
	{
		game->pos_x = 0;
		while (game->map[game->pos_y][game->pos_x])
			game->pos_x++;
		if (prev_len != game->pos_x)
		{
			free_array(game->map_copy);
			ft_error_launched("not rectangular map", game);
		}
		prev_len = game->pos_x;
		game->pos_y++;
	}
	game->pos_x--;
	game->pos_y--;
	game->size_y = game->pos_y;
}

void	border_check(t_game *game)
{
	is_rectangle(game);
	while (game->pos_y >= 0)
	{
		if (game->map[game->pos_y][game->pos_x] != '1')
			ft_error_copy("incorrect map border", game);
		game->pos_y--;
	}
	while (game->pos_x >= 0)
	{
		if (game->map[game->size_y][game->pos_x] != '1')
			ft_error_copy("incorrect map border", game);
		game->pos_x--;
	}
	while (game->map[0][++game->pos_x])
		if (game->map[0][game->pos_x] != '1')
			ft_error_copy("incorrect map border", game);
	while (++game->pos_y <= game->size_y)
		if (game->map[game->pos_y][0] != '1')
			ft_error_copy("incorrect map border", game);
}

void	split_maps(t_game *game)
{
	game->map = ft_split(game->str, '\n');
	if (!game->map)
		ft_error("split", game);
	game->map_copy = ft_split(game->str, '\n');
	if (!game->map_copy)
	{
		free_array(game->map_copy);
		ft_error("split", game);
	}
	free(game->str);
}

void	ber_to_array(char *filename, t_game *game)
{
	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0)
		ft_error("fd", game);
	game->line = get_next_line(game->fd);
	if (!game->line)
		ft_error_empty_map("get_next_line", game);
	game->str = ft_calloc(1, sizeof(char));
	if (!game->str)
		ft_error("calloc on game->str", game);
	while (game->line)
	{
		game->str = ft_strjoin_free(game->str, game->line);
		if (!game->str)
			ft_error("ft_strjoin with game->str & game->line", game);
		game->line = get_next_line(game->fd);
	}
	if (check_str(game->str))
		return (ft_error("incorrect map", game));
	split_maps(game);
	border_check(game);
	map_check(game);
}
