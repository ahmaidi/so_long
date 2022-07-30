/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_C_N_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:41:36 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/22 15:32:22 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_collect(t_vars *data)
{
	int	j;
	int	i;

	data->nb_collect = 0;
	data->nb_enmy = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->nb_collect++;
			if (data->map[i][j] == 'N')
				data->nb_enmy++;
			j++;
		}
		i++;
	}
}
