/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_coll_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:37:56 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/23 17:11:52 by ahmaidi          ###   ########.fr       */
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
			if (data->map[i][j] == 'C' && k < data->nb_collect)
			{
				data->positions_col[k].x = i;
				data->positions_col[k].y = j;
				k++;
			}
			j++;
		}
		i++;
	}
}

t_vars	*position_of_coll(t_vars *data)
{
	int	k;

	k = 0;
	data->positions_col = ft_calloc(data->nb_collect, sizeof(t_coordinate));
	if (!data->positions_col)
		return (NULL);
	fill_position(data);
	return (data);
}
