/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enms_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:13:11 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 15:21:35 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flag_0_bonus(t_list *l, t_enemy *tab, int y)
{
	if (tab[y].flag == 0
		&& (l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm + 1] == '1'
		|| l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm + 1] == 'C'
		|| l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm + 1] == 'E'
		|| l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm + 1] == 'N'))
		tab[y].flag = 1;
	else if (tab[y].flag == 1
		&& (l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm - 1] == '1'
		|| l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm - 1] == 'C'
		|| l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm - 1] == 'E'
		|| l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm - 1] == 'N'))
		tab[y].flag = 0;
}

void	animation_aller_bonus(t_list *l, t_enemy *tab, int y)
{
	int	c;

	c = (50000 * 3) / numbr_enm_bonus(l);
	decalage_bonus(c);
	mlx_put_image_to_window(l->mlx, l->mlx_win,
		l->img, (tab[y].x_pos_enm) * 64, tab[y].y_pos_enm * 64);
	l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm] = '0';
	tab[y].x_pos_enm++;
	mlx_put_image_to_window(l->mlx, l->mlx_win,
		l->en, (tab[y].x_pos_enm) * 64, tab[y].y_pos_enm * 64);
	if (l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm] == 'P')
	{
		write(1, "game over\n", 9);
		exit(0);
	}
	l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm] = 'N';
	if (l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm + 1] == '1'
	|| l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm + 1] == 'C'
	|| l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm + 1] == 'E')
		tab[y].flag = 1;
}

void	animation_reteur_bonus(t_list *l, t_enemy *tab, int y)
{
	int	c;

	c = (50000 * 6) / numbr_enm_bonus(l);
	decalage_bonus(c);
	mlx_put_image_to_window(l->mlx, l->mlx_win, l->img,
		(tab[y].x_pos_enm) * 64, tab[y].y_pos_enm * 64);
	l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm] = '0';
	tab[y].x_pos_enm--;
	if (l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm] == 'P')
	{
		write(1, "game over\n", 9);
		exit(0);
	}
	if (l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm - 1] == 'N'
	|| l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm - 1] == '1'
	|| l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm - 1] == 'E'
	|| l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm - 1] == 'C')
		tab[y].flag = 0;
	mlx_put_image_to_window(l->mlx, l->mlx_win, l->en,
		(tab[y].x_pos_enm) * 64, tab[y].y_pos_enm * 64);
	l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm] = 'N';
}

void	complete_mouv_enm_bonus(t_list *l, int y)
{
	t_enemy	*tab;
	int		c;

	c = (50000 * 6) / numbr_enm_bonus(l);
	decalage_bonus(c);
	tab = l->enemy->ar;
	flag_0_bonus(l, tab, y);
	if (tab[y].flag == 0
		&& l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm + 1] != '1'
		&& l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm + 1] != 'C'
		&& l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm + 1] != 'E'
		&& l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm + 1] != 'N')
		animation_aller_bonus(l, tab, y);
	else if (tab[y].flag == 1)
	{
		if (tab[y].flag == 1
			&& l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm -1] != '1'
			&& l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm -1] != 'E'
			&& l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm -1] != 'N'
			&& l->stock[tab[y].y_pos_enm][tab[y].x_pos_enm -1] != 'C')
			animation_reteur_bonus(l, tab, y);
	}
}

int	mouv_enmi_bonus(t_list *l)
{
	int		y;

	y = 0;
	while (y < numbr_enm_bonus(l))
	{
		complete_mouv_enm_bonus(l, y);
		y++;
	}
	return (1);
}
