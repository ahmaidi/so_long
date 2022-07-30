/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:27:46 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/25 15:52:09 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_it_left(t_vars *data, int i)
{
	if (data->map[data->positions_en[i].x]
		[data->positions_en[i].y + 1] != 'C'
		&& data->map[data->positions_en[i].x]
		[data->positions_en[i].y + 1] != 'E'
		&& data->map[data->positions_en[i].x]
		[data->positions_en[i].y + 1] != '1')
	{
		if (data->map[data->positions_en[i].x]
			[data->positions_en[i].y + 1] == 'P')
		{
			draw(data->img_enemy, data, data->positions_en[i].y + 1,
				data->positions_en[i].x);
			draw(data->img_bk, data, data->positions_en[i].y + 1,
				data->positions_en[i].x);
			ft_lose(data);
		}
		draw(data->img_enemy, data, data->positions_en[i].y + 1,
			data->positions_en[i].x);
		draw(data->img_bk, data, data->positions_en[i].y,
			data->positions_en[i].x);
		data->map[data->positions_en[i].x]
		[data->positions_en[i].y++] = '0';
			data->map[data->positions_en[i].x]
		[data->positions_en[i].y] = 'N';
	}
}

static void	draw_it_right(t_vars *data, int i)
{
	if (data->map[data->positions_en[i].x]
		[data->positions_en[i].y - 1] != 'C'
		&& data->map[data->positions_en[i].x]
		[data->positions_en[i].y - 1] != 'E'
		&& data->map[data->positions_en[i].x]
		[data->positions_en[i].y - 1] != '1')
	{
		if (data->map[data->positions_en[i].x]
			[data->positions_en[i].y - 1] == 'P')
		{
			draw(data->img_enemy, data, data->positions_en[i].y - 1,
				data->positions_en[i].x);
			draw(data->img_bk, data, data->positions_en[i].y - 1,
				data->positions_en[i].x);
			ft_lose(data);
		}
		draw(data->img_enemy, data, data->positions_en[i].y - 1,
			data->positions_en[i].x);
		draw(data->img_bk, data, data->positions_en[i].y,
			data->positions_en[i].x);
		data->map[data->positions_en[i].x]
		[data->positions_en[i].y--] = '0';
			data->map[data->positions_en[i].x]
		[data->positions_en[i].y] = 'N';
	}
}

int	animate_enemy(t_vars *data)
{
	int	i;

	if (data->animate_en == 8000)
	{
		i = 0;
		while (i < data->nb_enmy)
		{
			draw_it_left(data, i);
			i++;
		}
	}
	if (data->animate_en == 20000)
	{
		i = 0;
		while (i < data->nb_enmy)
		{
			draw_it_right(data, i);
			i++;
		}
		data->animate_en = 0;
	}
	data->animate_en++;
	return (0);
}
