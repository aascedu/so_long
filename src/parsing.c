/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:49:55 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/14 13:18:31 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_to_array(char *filename, t_game *game)
{
	char	*line;
	char	*str;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	str = ft_calloc(1, sizeof(char));
	if (!line || !str)
		ft_error();
	while (line)
	{
		str = ft_strjoin_free(str, line);
		line = get_next_line(fd);
	}
	if (check_str(str))
	{
		game->arg_valid = 1;
		return (free(str), 1);
	}
	game->map = ft_split(str, '\n');
	return (free(str), 0);
}
