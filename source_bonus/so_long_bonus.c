/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:55:33 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/23 15:18:16 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_vars	*data;

	data = malloc(sizeof(t_vars));
	if (argc == 2)
	{
		detecte_error(argv[1], data);
		init(data);
		draw_map(data);
	}
	else if (argc == 1)
	{
		error("\033[33mHint:./so_long_bonus file.ber !!\n", data);
	}
	else
	{
		error("\033[91mtoo many arguments !!\n", data);
	}
	return (0);
}
