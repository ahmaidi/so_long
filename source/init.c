/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:52:14 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/17 13:44:50 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_it(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}

static void	map_sizes(t_vars *data)
{
	int	i;

	i = 0;
	data->map_width = ft_strlen(data->map[0]) * 50;
	while (data->map[i])
		i++;
	data->map_height = i * 50;
}

static void	init_imges(t_vars *data)
{
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "./imgs/wall.xpm",
			&(data->img_width), &(data->img_height));
	data->img_bk = mlx_xpm_file_to_image(data->mlx, "./imgs/bk.xpm",
			&(data->img_width), &(data->img_height));
	data->img_player = mlx_xpm_file_to_image(data->mlx,
			"./imgs/player/player1.xpm",
			&(data->img_width), &(data->img_height));
	data->img_col = mlx_xpm_file_to_image(data->mlx, "./imgs/coins/C_1.xpm",
			&(data->img_width), &(data->img_height));
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "./imgs/Exit.xpm",
			&(data->img_width), &(data->img_height));
	data->img_enemy = mlx_xpm_file_to_image(data->mlx, "./imgs/enemy/fire2.xpm",
			&(data->img_width), &(data->img_height));
}

static void	init_moves_player(t_vars *data)
{
	data->p_lf_1 = mlx_xpm_file_to_image(data->mlx, "./imgs/l/l_1.xpm",
			&(data->img_width), &(data->img_height));
	data->p_lf_2 = mlx_xpm_file_to_image(data->mlx, "./imgs/l/l_2.xpm",
			&(data->img_width), &(data->img_height));
	data->p_lf_3 = mlx_xpm_file_to_image(data->mlx, "./imgs/l/l_3.xpm",
			&(data->img_width), &(data->img_height));
	data->p_lf_4 = mlx_xpm_file_to_image(data->mlx, "./imgs/l/l_4.xpm",
			&(data->img_width), &(data->img_height));
	data->p_rt_1 = mlx_xpm_file_to_image(data->mlx, "./imgs/r/r_1.xpm",
			&(data->img_width), &(data->img_height));
	data->p_rt_2 = mlx_xpm_file_to_image(data->mlx, "./imgs/r/r_2.xpm",
			&(data->img_width), &(data->img_height));
	data->p_rt_3 = mlx_xpm_file_to_image(data->mlx, "./imgs/r/r_3.xpm",
			&(data->img_width), &(data->img_height));
	data->p_rt_4 = mlx_xpm_file_to_image(data->mlx, "./imgs/r/r_4.xpm",
			&(data->img_width), &(data->img_height));
}

void	init(t_vars *data)
{
	data->mlx = mlx_init();
	map_sizes(data);
	data->mlx_win = mlx_new_window(data->mlx, data->map_width,
			data->map_height, "so_long");
	mlx_hook(data->mlx_win, 17, 1, close_it, data);
	init_imges(data);
	init_moves_player(data);
	count_collect(data);
	data->moves = 0;
	data->i = 0;
	data->dir = 0;
	data->on = 0;
	data->lose = 0;
	position_player(data);
}
