/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:49:55 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/13 15:06:40 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ber_to_array(char *filename, t_game *game)
{
	int		i;
	int		fd;
	char	*line;
	char	*string;
	//char	**array;

	string = ft_calloc(1, sizeof(char));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		game->arg_valid = 1;
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	// string = ft_strjoin(line, string);
	i = 0;
    while (line || i == 0)
    {
        line = get_next_line(fd);
		string = ft_strjoin_free(string, line);
        // ft_printf("line :%s", line);
        // free(line);
        i++;
		// ft_printf("string :%s", string);
    }
	game->map = ft_split(string, '\n');
}
