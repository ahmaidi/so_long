/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:27:56 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/16 13:13:34 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lose(t_vars *data)
{
	data->lose = 1;
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_string_put(data->mlx, data->mlx_win, data->map_width / 2,
		data->map_height / 2, 0xFFF00000, "YOU LOSE");
}
