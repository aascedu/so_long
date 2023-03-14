/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:49:55 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/14 14:56:54 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_to_array(char *filename, t_game *game)
{
	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0)
		ft_error("fd");
	game->line = get_next_line(game->fd);
	if (!game->line)
		ft_error("get_next_line");
	game->str = ft_calloc(1, sizeof(char));
	if (!game->str)
		ft_error("calloc");
	while (game->line)
	{
		game->str = ft_strjoin_free(game->str, game->line);
		if (!game->str)
			ft_error("ft_strjoin");
		game->line = get_next_line(game->fd);
		if (!game->line)
			ft_error("get_next_line");
	}
	if (check_str(game->str))
		return (ft_error("map"), 1);
	game->map = ft_split(game->str, '\n');
	if (!game->map)
		ft_error("split");
	return (free(game->str), 0);
}
