/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_component_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 06:25:32 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/21 12:03:23 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_components(int c, t_vars *data, int x, int y)
{
	if (c == '1')
		draw(data->img_wall, data, y, x);
	else if (c == 'P')
		draw(data->img_player, data, y, x);
	else if (c == 'E')
		draw(data->img_exit, data, y, x);
	else if (c == 'C')
		draw(data->img_col, data, y, x);
	else if (c == 'N')
		draw(data->img_enemy, data, y, x);
}
