/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:53:48 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/05/17 16:59:59 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_components
{
	int		nber_one_in_sides;
	int		nbr_player;
	int		nbr_exit;
	int		nbr_collectible;
}t_components;

typedef struct s_coordinate
{
	int	x;
	int	y;
}t_coordinate;

typedef struct s_vars
{
	int				error;
	void			*mlx;
	void			*mlx_win;
	void			*img;
	int				img_width;
	int				img_height;
	char			**map;
	int				map_height;
	int				map_width;
	void			*img_wall;
	void			*img_player;
	void			*img_bk;
	void			*img_col;
	void			*img_exit;
	void			*img_enemy;
	void			*p_lf_1;
	void			*p_lf_2;
	void			*p_lf_3;
	void			*p_lf_4;
	void			*p_rt_1;
	void			*p_rt_2;
	void			*p_rt_3;
	void			*p_rt_4;
	int				nb_collect;
	int				lose;
	int				win;
	int				on;
	int				i;
	int				dir;
	int				moves;
	t_coordinate	position;	
}t_vars;

/*------------reading MAP---------*/

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c);
void	filling_map(t_vars *data, int fd);
void	detecte_error(char *str, t_vars *data);
char	**ft_split(char *s, char c);
char	*free_it(char **tab);
int		ft_strcmp(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	error(char *s, t_vars *data);
void	chack_components(t_vars *data);
/*-------------------------------------------------------*/

/*-------------------- Drawing MAP -----------------------------------*/

void	init(t_vars *data);
void	count_collect(t_vars *data);
void	draw_map(t_vars	*data);
void	draw_components(int c, t_vars *data, int i, int j);
void	position_player(t_vars *data);
void	draw(void *img, t_vars *data, int i, int j);
char	*ft_itoa(int n);
int		rander_frame(t_vars	*data);
void	count_it(t_vars *data);
int		draw_collect(t_vars *data);
t_vars	*position_of_enemy(t_vars *data);
void	ft_lose(t_vars *data);
void	ft_win(t_vars *data);
void	ft_retry(t_vars *data);

/*-------------------------------------------------------*/

/* ------- KEY_HOOK -------------*/
int		key_hook(int keycode, t_vars *data);
void	key_hook_d(t_vars *data);
void	key_hook_a(t_vars *data);
void	key_hook_s(t_vars *data);
void	key_hook_w(t_vars *data);

#endif