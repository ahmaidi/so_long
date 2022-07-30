/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 06:18:15 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/25 15:57:11 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	char	*join_it(char const *s1, char const *s2)
{
	char			*str_join;
	size_t			len;
	unsigned int	i;

	if (!s1 && s2)
		return (ft_strdup(s2));
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str_join = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_join)
		return (NULL);
	while (s1[i])
	{
		str_join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str_join[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	str_join[i + ft_strlen(s1)] = '\0';
	return (str_join);
}

void	count_it(t_vars *data)
{
	char	*str;
	char	*str1;
	char	*str2;

	str = ft_itoa(data->moves);
	str1 = join_it(str, "\n");
	free(str);
	str2 = join_it("moves: ", str1);
	free(str1);
	ft_putstr_fd(str2, 0);
	free(str2);
}
