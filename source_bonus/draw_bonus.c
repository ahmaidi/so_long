/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 06:26:55 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/21 12:03:20 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw(void *img, t_vars *data, int x, int y)
{
	if (!data->lose)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			img, x * 50, y * 50);
}
