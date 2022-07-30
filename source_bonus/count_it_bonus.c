/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_it_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 06:18:15 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/21 12:02:58 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_it(t_vars *data)
{
	char	*str;

	str = ft_itoa(data->moves);
	if (!data->lose)
	{
		draw(data->img_bk, data, 0, 0);
		mlx_string_put(data->mlx, data->mlx_win, 1 * 13,
			1 * 13, 0x00000FFF, str);
	}
	free(str);
}
