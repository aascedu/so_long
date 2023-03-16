/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:49:55 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/16 11:50:51 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_check(t_game *game, char **map)
{
	(void)game;
	(void)map;
	return (NULL);
}

void	is_rectangle(t_game *game)
{
	game->pos_x = 0;
	game->pos_y = 0;
	while (game->map[0][game->pos_x])
		game->pos_x++;
	while (game->map[game->pos_y])
		game->pos_y++;
	if (game->pos_x == game->pos_y)
		ft_error_launched("rectangular map", game);
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
			ft_error_launched("incorrect map", game);
		game->pos_y--;
	}
	while (game->pos_x >= 0)
	{
		if (game->map[game->size_y][game->pos_x] != '1')
			ft_error_launched("incorrect map", game);
		game->pos_x--;
	}
	while (game->map[0][++game->pos_x])
		if (game->map[0][game->pos_x] != '1')
			ft_error_launched("incorrect map", game);
	while (++game->pos_y <= game->size_y)
		if (game->map[game->pos_y][0] != '1')
			ft_error_launched("incorrect map", game);
}

void	ber_to_array(char *filename, t_game *game)
{
	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0)
		ft_error("fd", game);
	game->line = get_next_line(game->fd);
	if (!game->line)
		ft_error("get_next_line", game);
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
	game->map = ft_split(game->str, '\n');
	if (!game->map)
		ft_error("split", game);
	free(game->str);
	border_check(game);
	map_check(game, game->map);
}
