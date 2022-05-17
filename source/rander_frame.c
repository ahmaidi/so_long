/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 06:13:28 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/16 12:22:22 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	draw_left(t_vars *data)
{
	if (data->i == 0)
		draw(data->p_lf_1, data,
			data->position.x, data->position.y);
	if (data->i == 1)
		draw(data->p_lf_2, data,
			data->position.x, data->position.y);
	if (data->i == 2)
		draw(data->p_lf_2, data,
			data->position.x, data->position.y);
	if (data->i == 3)
		draw(data->p_lf_4, data,
			data->position.x, data->position.y);
}

static	void	draw_right(t_vars *data)
{
	if (data->i == 0)
		draw(data->p_rt_1, data,
			data->position.x, data->position.y);
	if (data->i == 1)
		draw(data->p_rt_2, data,
			data->position.x, data->position.y);
	if (data->i == 2)
		draw(data->p_rt_3, data,
			data->position.x, data->position.y);
	if (data->i == 3)
		draw(data->p_rt_4, data,
			data->position.x, data->position.y);
}

int	rander_frame(t_vars	*data)
{
	if (data->on)
	{
		draw(data->img_bk, data, data->position.x, data->position.y);
		if (data->dir)
			draw_left(data);
		else
			draw_right(data);
		data->i++;
		data->i = data->i % 4;
	}
	return (0);
}
