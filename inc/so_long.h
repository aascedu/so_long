/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:28:22 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/16 11:33:14 by aascedu          ###   ########lyon.fr   */
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
	int		fd;
	char	*str;
	char	*line;
	int		pos_x;
	int		pos_y;
	int		size_y;
}		t_game;

// error.c functions
int		check_str(char *str);
int		check_filename(char *filename);
int		check_directory(char *filename);
int		valid_arg(char *filename);

// parsing.c functions
void	ber_to_array(char *filename, t_game *game);
void	border_check(t_game *game);
char	**map_check(t_game *game, char **map);

// exit.c functions
void	free_array(char **array);
void	ft_error(char *str, t_game *game);
void	ft_error_launched(char *str, t_game *game);

#endif