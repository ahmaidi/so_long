/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:05:51 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/07/30 21:05:18 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	empty_lines(char *s, t_vars *d)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
		{
			d->error = 1;
			error("\033[91mThere's Empty lines in the Map", d);
		}
		i++;
	}
}

static void	ft_check_compenent(char *line, t_vars *data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'C' && line[i] != 'P' && line[i] != 'E'
			&& line[i] != '1' && line[i] != '0'
			&& line[i] != 'N' && line[i] != '\n')
		{
			data->error = 1;
			error("\033[91mThere is a character invalid !!\n", data);
		}
		i++;
	}
}

void	filling_map(t_vars *data, int fd)
{
	char	*line;
	char	*str;

	str = NULL;
	line = get_next_line(fd);
	if (line == NULL)
	{
		data->error = 1;
		error("\033[91mEmpty Map!!\n", data);
	}
	while (line)
	{
		ft_check_compenent(line, data);
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(fd);
	}
	empty_lines(str, data);
	data->map = ft_split(str, '\n');
	free(str);
	close(fd);
}
