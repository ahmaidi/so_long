/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:36:47 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/21 12:03:36 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error(char *s, t_vars *data)
{
	if (data->map && data->error == 0)
		free_it(data->map);
	write(2, "ERROR\n", 6);
	write(2, s, ft_strlen(s));
	exit (1);
}
