/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_it.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:01:13 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/21 15:02:33 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	render_it(int keycode, t_vars *data)
{
	if (data->render_frame)
	{
		if (keycode == 2 || keycode == 124)
		{
			key_hook_d(data);
			data->dir = 1;
		}
		if (keycode == 0 || keycode == 123)
		{
			key_hook_a(data);
			data->dir = 0;
		}
		if (keycode == 1 || keycode == 125)
			key_hook_s(data);
		if (keycode == 13 || keycode == 126)
			key_hook_w(data);
		if (keycode == 1 || keycode == 13 || keycode == 0 || keycode == 2
			|| keycode == 126 || keycode == 125 || keycode == 124
			|| keycode == 123)
		{
			data->on = 1;
			count_it(data);
		}
	}
	return (0);
}
