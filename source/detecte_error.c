/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detecte_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:56:23 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/17 17:01:12 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	after_point(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			return (i);
		i++;
	}
	return (i);
}

static void	check_rectangle(t_vars *data)
{
	int	j;

	j = 0;
	while (data->map[j])
	{
		if (ft_strlen(data->map[j]) != ft_strlen(data->map[0]))
			error("\033[91mThe map must be rectangular !!\n", data);
		j++;
	}
	data->map_height = j;
	if ((int)ft_strlen(data->map[0]) == j)
		error("\033[91mThe map must be rectangular !!\n", data);
}

static void	check_walls_up_down(char *first, char *last, t_vars *data)
{
	int	i;

	i = 0;
	while (first[i] && last[i])
	{
		if (first[i] != '1' || last[i] != '1')
			error("\033[91mThe map must be closed/surrounded by walls !!\n",
				data);
		i++;
	}
}

void	detecte_error(char *str, t_vars *data)
{
	int		fd;

	data->error = 0;
	if (ft_strcmp(str + after_point(str), ".ber"))
		error("\033[91mthe extension of the file must be (.ber)!!\n", data);
	fd = open(str, O_RDONLY, 0644);
	if (fd < 0)
	{
		error("\033[91mNo such file or directory !!\n", data);
		exit(1);
	}
	filling_map(data, fd);
	check_rectangle(data);
	check_walls_up_down(data->map[0], data->map[data->map_height - 1], data);
	chack_components(data);
}
