/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:21:30 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/21 13:25:07 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_vars *data)
{
	data->render_frame = 0;
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_string_put(data->mlx, data->mlx_win, data->map_width
		/ 2, data->map_height / 2, 0x000FF000, "YOU WIN");
}
