/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:07:45 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/24 15:49:54 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_image(t_game *game)
{
	if (game->ground)
		mlx_destroy_image(game->mlx_ptr, game->ground);
	if (game->wall != NULL)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->collect)
		mlx_destroy_image(game->mlx_ptr, game->collect);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->map)
		free_array(game->map);
	if (game->win_ptr && game->mlx_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}	
	exit (1);
}

void	create_image(t_game *game)
{
	game->ground = NULL;
	game->wall = NULL;
	game->player = NULL;
	game->collect = NULL;
	game->exit = NULL;
	game->ground = mlx_xpm_file_to_image(game->mlx_ptr, "assets/ground.xpm", \
	&game->img_width, &game->img_height);
	if (game->ground == NULL)
		destroy_image(game);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "assets/wall.xpm", \
	&game->img_width, &game->img_height);
	if (game->wall == NULL)
		destroy_image(game);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "assets/jul.xpm", \
	&game->img_width, &game->img_height);
	if (game->player == NULL)
		destroy_image(game);
	game->collect = mlx_xpm_file_to_image(game->mlx_ptr, "assets/ovni.xpm", \
	&game->img_width, &game->img_height);
	if (game->collect == NULL)
		destroy_image(game);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "assets/tmax.xpm", \
	&game->img_width, &game->img_height);
	if (game->exit == NULL)
		destroy_image(game);
}

void	replace_map(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->wall, j * 96, i * 96);
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->ground, j * 96, i * 96);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->collect, j * 96, i * 96);
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->player, j * 96, i * 96);
}

void	display_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			replace_map(game, i, j);
			if (game->pos_x == game->exit_x && game->pos_y == game->exit_y)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->player, game->exit_x * 96, game->exit_y * 96);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->exit, game->exit_x * 96, game->exit_y * 96);
		}
		if (game->nb_collected == game->nb_to_collect
			&& (game->pos_x == game->exit_x && game->pos_y == game->exit_y))
			destroy_image(game);
	}
}
