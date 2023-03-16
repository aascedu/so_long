/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:49:00 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/16 11:49:46 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **array)
{
	int	i;
	
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_error(char *str, t_game *game)
{
	ft_printf("%s : has made the program crash !\n", str);
	if (ft_strncmp(str, "fd", ft_strlen(str)) == 0)
		exit(1);
	free(game->str);
	free(game->line);
	if (ft_strncmp(str, "split", ft_strlen(str)) == 0)
		free_array(game->map);
	exit(1);
}

void	ft_error_launched(char *str, t_game *game)
{
	ft_printf("%s : has made the program crash !\n", str);
	free_array(game->map);
	exit (1);
}