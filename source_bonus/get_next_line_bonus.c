/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:25:11 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/21 12:04:15 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*get_line(char **stock)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while ((*stock)[i] != '\n')
		i++;
	line = ft_substr(*stock, 0, i + 1);
	tmp = *stock;
	*stock = ft_substr(*stock, i + 1, ft_strlen(*stock) - i);
	free(tmp);
	return (line);
}

static char	*get_stock(char	**stock)
{
	char	*ligne;

	if (*stock && **stock != '\0')
	{
		ligne = *stock;
		*stock = NULL;
		return (ligne);
	}
	else
	{
		free(*stock);
		*stock = NULL;
		return (NULL);
	}
}

static char	*free_its(char *buffer, char *stock)
{
	free(buffer);
	free(stock);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stock;
	int			read_f;

	if (fd < 0)
		return (NULL);
	buffer = malloc((1 + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stock, '\n'))
	{
		read_f = read(fd, buffer, 1);
		if (read_f < 0)
			return (free_its(buffer, stock));
		if (read_f == 0)
			break ;
		buffer[read_f] = 0;
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	if (ft_strchr(stock, '\n'))
		return (get_line(&stock));
	return (get_stock(&stock));
}
