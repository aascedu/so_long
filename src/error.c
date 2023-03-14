/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:44:42 by arthurasced       #+#    #+#             */
/*   Updated: 2023/03/14 13:20:21 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	
}

int	check_str(char *str)
{
	int	i;

	
	i = 0;
	while (str && str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != '\n' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != 'P')
			return (1);
		i++;
	}
	return (0);
}

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

int	valid_arg(char *filename)
{
	if (check_filename(filename))
		return (1);
	if (check_directory(filename))
		return (1);
	return (0);
}
