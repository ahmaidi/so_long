/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_enemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:39:43 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/23 15:17:31 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	fill_position(t_vars *data)
{
	int	j;
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' && k < data->nb_enmy)
			{
				data->positions_en[k].x = i;
				data->positions_en[k].y = j;
				k++;
			}
			j++;
		}
		i++;
	}
}

t_vars	*position_of_enemy(t_vars *data)
{
	int	k;

	k = 0;
	data->positions_en = ft_calloc(data->nb_enmy, sizeof(t_coordinate));
	if (!data->positions_en)
		return (NULL);
	fill_position(data);
	return (data);
}
