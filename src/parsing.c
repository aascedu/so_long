/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurascedu <arthurascedu@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:44:42 by arthurasced       #+#    #+#             */
/*   Updated: 2023/03/10 15:13:01 by arthurasced      ###   ########lyon.fr   */
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
	return (0);
}

