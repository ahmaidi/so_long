/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 06:26:55 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/21 13:17:11 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(void *img, t_vars *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		img, x * 50, y * 50);
}
