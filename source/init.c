/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:52:14 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/21 12:37:25 by ahmaidi          ###   ########.fr       */
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
			"./imgs/player/player_m.xpm",
			&(data->img_width), &(data->img_height));
	data->img_col = mlx_xpm_file_to_image(data->mlx, "./imgs/coins/C_1.xpm",
			&(data->img_width), &(data->img_height));
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "./imgs/Exit.xpm",
			&(data->img_width), &(data->img_height));
	data->img_enemy = mlx_xpm_file_to_image(data->mlx, "./imgs/enemy/fire2.xpm",
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
	count_collect(data);
	data->moves = 0;
	position_player(data);
}
