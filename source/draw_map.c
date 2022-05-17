/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:26:59 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/17 14:11:57 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_stop(int keycode, t_vars	*data)
{
	(void) keycode;
		data->on = 0;
	return (0);
}

void	draw_map(t_vars	*data)
{
	int		x;
	int		y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			draw_components(data->map[x][y], data, x, y);
			y++;
		}
		x++;
	}
	mlx_hook(data->mlx_win, 3, 0, ft_stop, data);
	mlx_loop_hook(data->mlx, rander_frame, data);
	mlx_hook(data->mlx_win, 2, 1, key_hook, data);
	mlx_loop(data->mlx);
}
