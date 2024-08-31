/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:24:42 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 15:20:18 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

typedef struct s_enemy
{
	int				y_enemy;
	int				x_enemy;
	int				nbr_enm;
	int				y_pos_enm;
	int				x_pos_enm;
	int				*ar_pos;
	int				flag;
	struct s_enemy	*ar;
}	t_enemy;

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
	struct s_enemy	*enemy;
	char			**arr1;
	char			**arr2;
}	t_list;

void	erreur_bonus(void);
char	*ft_strcpy_bonus(char *dest, char *src);
int		check_ber_bonus(int ac, char **av);
int		ft_strchr_bonus(char *s, int c);
char	*ft_strjoin_bonus(char *s1, char *s2);
char	*read_get_bonus(char *counter, int fd);
char	*get_next_line_bonus(int fd);
int		ft_strlen_bonus(char *str);
char	*ft_update_bonus(char *counter);
char	*return_ligne_bonus(char *counter, char *str);
char	*ft_strdup_bonus(const char *s);
char	*ft_line_bonus(char *counter);
int		ft_strncmp_bonus(char *s1, char *s2, size_t n);
void	free_spit_bonus(char **split);
int		ft_calcul_bonus(long int n);
char	*ft_itoa_bonus(int n);
void	inis_bonus(t_list *m);
void	erreur_bonus(void);
int		cherch_caracter_bonus(t_list *m);
void	check_line_1_bonus(t_list *l);
int		check_ber_bonus(int ac, char **av);
int		open_file_bonus(t_list *m, char **av);
void	stock_map_bonus(t_list *l, char **av);
void	inis_mlx_pointer_bonus(t_list *l);
void	put_img_map_bonus(t_list *l);
int		ft_exit_bonus(int c, void *param);
int		mouv_enmi_bonus(t_list *l);
t_enemy	*stock_enm_bonus(t_list *l);
int		numbr_enm_bonus(t_list *l);
int		mouve_p_bonus(int c, t_list *l);
void	decalage_bonus(int c);
int		numbr_enm_bonus(t_list *l);
void	mouv_player_2_bonus(t_list *l, int c);
int		mouve_p_bonus(int c, t_list *l);
void	printf_count_bonus(t_list *l);
void	mouv_player_droit_bonus(t_list *l);
void	mouv_player_gauch_bonus(t_list *l);
void	mouv_player_haut_bonus(t_list *l);
void	mouv_player_bas_bonus(t_list *l);
int		ft_exit_bonus(int c, void *param);
void	flood_fill_bonus(char **stock, int *arr);
void	check_flood_bonus(t_list *l, t_i *i);
void	inisalisation_variable_bonus(t_i *i);
int		rest_flood_fill_bonus(t_list *l);
void	animation_player_bonus(t_list *l);
void	animation_player_inverse_bonus(t_list *l);
void	alloc_array1_bonus(t_list *l);
int		chec_alpha_bonus(t_list *l);
void	alpha_bonus(t_list *l);
void	check_nbr_enms_bonus(t_list *l);
t_enemy	*stock_enm_bonus(t_list *l);
#endif