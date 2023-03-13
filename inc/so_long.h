/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:28:22 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/13 15:04:19 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/include/libft.h"
# include <unistd.h>

typedef struct s_game
{
	int		arg_valid;
	void	*mlx_ptr;
	void	*win_ptr;
	int		steps;
	char	**map;
}		t_game;

int		check_filename(char *filename);
void	valid_arg(char *filename, t_game *game);
void	ber_to_array(char *filename, t_game *game);

#endif