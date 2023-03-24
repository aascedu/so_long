/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:28:22 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/24 15:17:00 by aascedu          ###   ########lyon.fr   */
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
	char	**map_copy;
	int		fd;
	char	*str;
	char	*line;
	int		pos_x;
	int		pos_y;
	int		exit_x;
	int		exit_y;
	int		size_x;
	int		size_y;
	int		nb_to_collect;
	int		nb_collected;
	void	*ground;
	void	*wall;
	void	*collect;
	void	*player;
	void	*exit;
	int		img_width;
	int		img_height;
}		t_game;

typedef enum e_keycode
{
		a_key		=	97,
		d_key		=	100,
		s_key		=	115,
		w_key		=	119,
		esc_key		=	65307,
		left_key	=	65361,
		right_key	=	65363,
		down_key	=	65364,
		up_key		=	65362,
}		t_keycode;

// main.c functions
int	key_press(t_keycode keycode, t_game *game);

// check.c functions
int		map_correct(char *str, t_game *game);
int		check_str(char *str, t_game *game);
int		check_filename(char *filename);
int		check_directory(char *filename);

// exit.c functions
void	free_array(char **array);
void	ft_error_empty_map(char *str, t_game *game);
void	ft_error(char *str, t_game *game);
void	ft_error_launched(char *str, t_game *game);
void	ft_error_copy(char *str, t_game *game);

// image.c functions
void	create_image(t_game *game);
int		destroy_image(t_game *game);
void	display_map(t_game *game);

// init_window.c functions
void	init_my_window(t_game *game);

// move.c functions
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);

// map_recursive.c functions
void	find_start_pos(t_game *game);
void	find_exit_pos(t_game *game);
void	map_recursive(t_game *game, int y, int x);

// parsing.c functions
void	map_check(t_game *game);
void	is_rectangle(t_game *game);
void	border_check(t_game *game);
void	split_maps(t_game *game);
void	ber_to_array(char *filename, t_game *game);

#endif