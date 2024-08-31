/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:24:42 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 15:18:57 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21
# endif

typedef struct position_player
{
	int	y;
	int	x;
}	t_ply;

typedef struct inisialisation_variable
{
	int	x;
	int	c;
	int	i;
	int	m;
	int	n;
}	t_i;

typedef struct s_player
{
	int	y_p;
	int	x_p;
}	t_player;

typedef struct s_list
{
	int				fd;
	char			*line;
	char			*line1;
	int				countp;
	int				counte;
	int				countc;
	int				countesp;
	void			*mlx;
	void			*mlx_win;
	int				img_w;
	int				img_h;
	char			*img;
	char			*p;
	char			*w;
	char			*col;
	char			*b;
	char			*exit;
	char			*f;
	char			*relative_path;
	char			*r;
	char			*lfo9;
	char			*port_over;
	char			*pov;
	char			**stock;
	char			*game;
	char			*gam;
	char			*crono;
	char			*cro;
	char			*itois;
	char			*itois_col;
	char			*enm;
	char			*en;
	char			*game_over;
	char			*over;
	int				v;
	int				i;
	int				h;
	int				s;
	int				k;
	int				e;
	int				t;
	int				m;
	int				s1;
	int				s2;
	int				ss;
	int				x;
	int				hh;
	int				yy;
	int				y1;
	int				po;
	int				x1;
	int				y11;
	int				nbr_ling;
	int				p_player_y;
	int				p_player_x;
	char			**double_maps;
	char			*inv_player;
	char			*inv_pl;
	char			*close_bouch;
	char			*close;
	struct s_player	*plr;
}	t_list;

char	*ft_strcpy(char *dest, char *src);
int		check_ber(int ac, char **av);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*read_get(char *counter, int fd);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_update(char *counter);
char	*return_ligne(char *counter, char *str);
char	*ft_strdup(const char *s);
char	*ft_line(char *counter);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	free_spit(char **split);
int		ft_calcul(long int n);
char	*ft_itoa(int n);
void	inis(t_list *m);
void	erreur(void);
int		cherch_caracter(t_list *m);
void	check_line_1(t_list *l);
int		open_file(t_list *m, char **av);
void	stock_map(t_list *l, char **av);
void	inis_mlx_pointer(t_list *l);
void	put_img_map(t_list *l);
int		ft_exit(int c, void *param);
int		mouve_p(int c, t_list *l);
void	mouv_player_2(t_list *l, int c);
void	mouv_player_droit(t_list *l);
void	mouv_player_gauch(t_list *l);
void	mouv_player_haut(t_list *l);
void	mouv_player_bas(t_list *l);
void	flood_fill(char **stock, int *arr);
void	check_flood(t_list *l, t_i *i);
void	inisalisation_variable(t_i *i);
int		rest_flood_fill(t_list *l);
int		chec_alpha(t_list *l);
void	alpha(t_list *l);
void	putnber(int c);
#endif