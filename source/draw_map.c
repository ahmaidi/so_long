/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:26:59 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/21 13:26:08 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_vars	*data)
{
	int		x;
	int		y;

	x = 0;
	data->render_frame = 1;
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
	mlx_hook(data->mlx_win, 2, 1, key_hook, data);
	mlx_loop(data->mlx);
}
