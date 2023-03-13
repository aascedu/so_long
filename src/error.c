/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:44:42 by arthurasced       #+#    #+#             */
/*   Updated: 2023/03/13 15:10:25 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_filename(char *filename)
{
	if (filename[ft_strlen(filename) - 1] != 'r'
		|| filename[ft_strlen(filename) - 2] != 'e'
		|| filename[ft_strlen(filename) - 3] != 'b'
		|| filename[ft_strlen(filename) - 4] != '.')
		return (1);
	else if (!ft_strncmp(filename, "/.ber", ft_strlen(filename)))
		return (1);
	return (0);
}

int	check_directory(char *filename)
{
	int	fd;

	fd = open(filename, __O_DIRECTORY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

void	valid_arg(char *filename, t_game *game)
{
	game->arg_valid = 0;
	if (check_filename(filename))
		game->arg_valid = 1;
	if (check_directory(filename))
		game->arg_valid = 1;
}
