/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appel_fonction_mouv_player_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:57:28 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 14:53:39 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mouv_player_2_bonus(t_list *l, int c)
{
	if (l->countc == 0)
	{
		mlx_put_image_to_window(l->mlx,
			l->mlx_win, l->pov, l->s2 * 64, l->s1 * 64);
		printf_count_bonus(l);
	}
	if (c == 100)
	{
		mouv_player_droit_bonus(l);
		printf_count_bonus(l);
	}
	else if (c == 119)
	{
		mouv_player_bas_bonus(l);
		printf_count_bonus(l);
	}
}

int	mouve_p_bonus(int c, t_list *l)
{
	mouv_player_2_bonus(l, c);
	if (c == 97)
	{
		mouv_player_gauch_bonus(l);
		printf_count_bonus(l);
	}
	else if (c == 115)
	{
		mouv_player_haut_bonus(l);
		printf_count_bonus(l);
	}
	else if (c == 65307)
		exit(0);
	return (0);
}

int	ft_exit_bonus(int c, void *param)
{
	(void)param;
	(void)c;
	exit(1);
}

t_enemy	*stock_enm_bonus(t_list *l)
{
	int	i;
	int	j;
	int	d;

	i = 0;
	j = 0;
	d = 0;
	l->enemy->ar = malloc(sizeof(t_list) * l->enemy->nbr_enm);
	while (l->stock[i] && d < l->enemy->nbr_enm)
	{
		j = 0;
		while (l->stock[i][j] && d < l->enemy->nbr_enm)
		{
			if (l->stock[i][j] == 'N')
			{
				l->enemy->ar[d].x_pos_enm = j;
				l->enemy->ar[d].y_pos_enm = i;
				d++;
			}
			j++;
		}
		i++;
	}
	return (l->enemy->ar);
}

void	alpha_bonus(t_list *l)
{
	if (chec_alpha_bonus(l) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
