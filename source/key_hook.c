/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 08:44:54 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/17 16:53:19 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook_d(t_vars *data)
{
	if (data->map[data->position.y][data->position.x + 1] != '1' &&
			data->map[data->position.y][data->position.x + 1] != 'E'
			&& data->map[data->position.y][data->position.x + 1] != 'N')
	{
		data->moves++;
		draw(data->img_bk, data, data->position.x, data->position.y);
		if (data->map[data->position.y][data->position.x + 1] == 'C')
			data->nb_collect--;
		data->map[data->position.y][data->position.x + 1] = 'P';
		data->map[data->position.y][data->position.x] = '0';
		position_player(data);
	}
	else if (data->map[data->position.y][data->position.x + 1] == 'E' &&
		!data->nb_collect)
	{
		data->map[data->position.y][data->position.x + 1] = 'P';
		data->map[data->position.y][data->position.x] = '0';
		ft_win(data);
	}
	else if (data->map[data->position.y][data->position.x + 1] == 'N')
		ft_lose(data);
}

void	key_hook_a(t_vars *data)
{
	if (data->map[data->position.y][data->position.x - 1] != '1' &&
			data->map[data->position.y][data->position.x - 1] != 'E'
			&& data->map[data->position.y][data->position.x - 1] != 'N')
	{
		data->moves++;
		draw(data->img_bk, data, data->position.x, data->position.y);
		if (data->map[data->position.y][data->position.x - 1] == 'C')
			data->nb_collect--;
		data->map[data->position.y][data->position.x - 1] = 'P';
		data->map[data->position.y][data->position.x] = '0';
		position_player(data);
	}
	else if (data->map[data->position.y][data->position.x - 1] == 'E' &&
		!data->nb_collect)
	{
		data->map[data->position.y][data->position.x - 1] = 'P';
		data->map[data->position.y][data->position.x] = '0';
		ft_win(data);
	}
	else if (data->map[data->position.y][data->position.x - 1] == 'N')
		ft_lose(data);
}

void	key_hook_s(t_vars *data)
{
	if (data->map[data->position.y + 1][data->position.x] != '1' &&
			data->map[data->position.y + 1][data->position.x] != 'E'
			&& data->map[data->position.y + 1][data->position.x] != 'N')
	{
		data->moves++;
		draw(data->img_bk, data, data->position.x, data->position.y);
		if (data->map[data->position.y + 1][data->position.x] == 'C')
			data->nb_collect--;
		data->map[data->position.y + 1][data->position.x] = 'P';
		data->map[data->position.y][data->position.x] = '0';
		position_player(data);
	}
	else if (data->map[data->position.y + 1][data->position.x] == 'E' &&
		!data->nb_collect)
	{
		data->map[data->position.y + 1][data->position.x] = 'P';
		data->map[data->position.y][data->position.x] = '0';
		ft_win(data);
	}
	else if (data->map[data->position.y + 1][data->position.x] == 'N')
		ft_lose(data);
}

void	key_hook_w(t_vars *data)
{
	if (data->map[data->position.y - 1][data->position.x] != '1' &&
			data->map[data->position.y - 1][data->position.x] != 'E'
			&& data->map[data->position.y - 1][data->position.x] != 'N')
	{
		data->moves++;
		draw(data->img_bk, data, data->position.x, data->position.y);
		if (data->map[data->position.y - 1][data->position.x] == 'C')
			data->nb_collect--;
		data->map[data->position.y - 1][data->position.x] = 'P';
		data->map[data->position.y][data->position.x] = '0';
		position_player(data);
	}
	else if (data->map[data->position.y - 1][data->position.x] == 'E' &&
		!data->nb_collect)
	{
		data->map[data->position.y - 1][data->position.x] = 'P';
		data->map[data->position.y][data->position.x] = '0';
		ft_win(data);
	}
	else if (data->map[data->position.y - 1][data->position.x] == 'N')
		ft_lose(data);
}

int	key_hook(int keycode, t_vars *data)
{
	if (keycode == 53 || keycode == 12)
		exit(0);
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
		|| keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
	{
		data->on = 1;
		count_it(data);
	}
	return (0);
}
