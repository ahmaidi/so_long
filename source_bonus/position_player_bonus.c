/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 08:43:18 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/22 15:25:38 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	position_player(t_vars *data)
{
	int				i;
	int				j;

	i = 0;
	data->position.y = 0;
	while (data->map[i])
	{
		j = 0;
		data->position.x = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				break ;
			data->position.x++;
			j++;
		}
		if (data->map[i][j] == 'P')
			break ;
		data->position.y++;
		i++;
	}
}
