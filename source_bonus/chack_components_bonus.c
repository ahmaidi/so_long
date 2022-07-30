/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chack_components_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:43:46 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/21 12:02:42 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	error_component(t_components *component, t_vars *data)
{
	if (!component->nber_one_in_sides)
		error("\033[91mThe map must be closed/surrounded by walls !!\n", data);
	else if (component->nbr_player == 0 || component->nbr_player > 1)
		error("\033[91mThere is more than one player OR no player !!\n", data);
	else if (component->nbr_exit < 1)
		error("\033[91mThe map must be contain at least one exit !!\n", data);
	else if (component->nbr_collectible < 1)
		error("\033[91mThe map must be contain at least one collictble!!\n",
			data);
}

static void	initialize_component(t_components	*component)
{
	(*component).nber_one_in_sides = 1;
	(*component).nbr_player = 0;
	(*component).nbr_collectible = 0;
	(*component).nbr_exit = 0;
}

void	chack_components(t_vars *data)
{
	int				i;
	int				j;
	t_components	component;

	initialize_component(&component);
	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' ||
			data->map[i][ft_strlen(data->map[i]) - 1] != '1')
			component.nber_one_in_sides = 0;
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				component.nbr_exit++;
			else if (data->map[i][j] == 'C')
				component.nbr_collectible++;
			else if (data->map[i][j] == 'P')
				component.nbr_player++;
			j++;
		}
		i++;
	}
	error_component(&component, data);
}
