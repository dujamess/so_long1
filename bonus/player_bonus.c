/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:16:47 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 14:17:38 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	printf_count_bonus(t_list *l)
{
	l->itois = ft_itoa_bonus(l->ss);
	mlx_put_image_to_window(l->mlx, l->mlx_win, l->gam, 0 * 64, 0 * 64);
	mlx_string_put(l->mlx, l->mlx_win, 34, 30, 0xFFFFFF, l->itois);
	l->itois_col = ft_itoa_bonus(l->countc);
	mlx_put_image_to_window(l->mlx,
		l->mlx_win, l->cro, (l->h - 1) * 64, 0 * 64);
	mlx_string_put(l->mlx,
		l->mlx_win, (l->h -0.65) * 64, 25, 0xFFFFFF, l->itois_col);
	free(l->itois);
	free(l->itois_col);
}

void	mouv_player_droit_bonus(t_list *l)
{
	if (l->stock[l->plr->y_p][l->plr->x_p + 1] == 'N')
	{
		write(1, "Game over\n", 10);
		exit(0);
	}
	if (l->countc == 0 && l->stock[l->plr->y_p][l->plr->x_p + 1] == 'E')
	{
		write(1, "vous etes gagnier\n", 18);
		exit(0);
	}
	if (l->stock[l->plr->y_p][l->plr->x_p + 1] != 'E'
		&& l->stock[l->plr->y_p][l->plr->x_p + 1] != '1')
	{
		if (l->stock[l->plr->y_p][l->plr->x_p + 1] == 'C')
			l->countc--;
		mlx_put_image_to_window(l->mlx,
			l->mlx_win, l->img, l->plr->x_p * 64, l->plr->y_p * 64);
		l->stock[l->plr->y_p][l->plr->x_p] = '0';
		l->plr->x_p = l->plr->x_p + 1;
		l->stock[l->plr->y_p][l->plr->x_p] = 'P';
		l->ss++;
		animation_player_bonus(l);
		animation_player_bonus(l);
	}
}

void	mouv_player_gauch_bonus(t_list *l)
{
	if (l->stock[l->plr->y_p][l->plr->x_p - 1] == 'N')
	{
		write(1, "Game over\n", 10);
		exit(0);
	}
	if (l->countc == 0 && l->stock[l->plr->y_p][l->plr->x_p - 1] == 'E')
	{
		write(1, "vous etes gagnier\n", 18);
		exit(0);
	}
	if (l->stock[l->plr->y_p][l->plr->x_p - 1] != 'E'
		&& l->stock[l->plr->y_p][l->plr->x_p - 1] != '1')
	{
		if (l->stock[l->plr->y_p][l->plr->x_p - 1] == 'C')
			l->countc--;
		mlx_put_image_to_window(l->mlx,
			l->mlx_win, l->img, l->plr->x_p * 64, l->plr->y_p * 64);
		l->stock[l->plr->y_p][l->plr->x_p] = '0';
		l->plr->x_p = l->plr->x_p - 1;
		l->ss++;
		l->stock[l->plr->y_p][l->plr->x_p] = 'P';
		animation_player_inverse_bonus(l);
		animation_player_inverse_bonus(l);
	}
}

void	mouv_player_haut_bonus(t_list *l)
{
	if (l->stock[l->plr->y_p + 1][l->plr->x_p] == 'N')
	{
		write(1, "Game over\n", 10);
		exit(0);
	}
	if (l->countc == 0 && l->stock[l->plr->y_p + 1][l->plr->x_p] == 'E')
	{
		write(1, "vous etes gagnier\n", 18);
		exit(0);
	}
	if (l->stock[l->plr->y_p + 1][l->plr->x_p] != 'E'
		&& l->stock[l->plr->y_p + 1][l->plr->x_p] != '1')
	{
		if (l->stock[l->plr->y_p + 1][l->plr->x_p] == 'C')
			l->countc--;
		mlx_put_image_to_window(l->mlx, l->mlx_win,
			l->img, l->plr->x_p * 64, l->plr->y_p * 64);
		l->stock[l->plr->y_p][l->plr->x_p] = '0';
		l->plr->y_p = l->plr->y_p +1;
		l->stock[l->plr->y_p][l->plr->x_p] = 'P';
		l->ss++;
		animation_player_bonus(l);
		animation_player_bonus(l);
	}
}

void	mouv_player_bas_bonus(t_list *l)
{
	if (l->stock[l->plr->y_p - 1][l->plr->x_p] == 'N')
	{
		write(1, "Game over\n", 10);
		exit(0);
	}
	if (l->countc == 0 && l->stock[l->plr->y_p - 1][l->plr->x_p] == 'E')
	{
		write(1, "vous etes gagnier\n", 18);
		exit(0);
	}
	if (l->stock[l->plr->y_p - 1][l->plr->x_p] != 'E'
		&& l->stock[l->plr->y_p - 1][l->plr->x_p] != '1')
	{
		if (l->stock[l->plr->y_p - 1][l->plr->x_p] == 'C')
			l->countc--;
		mlx_put_image_to_window(l->mlx, l->mlx_win,
			l->img, l->plr->x_p * 64, l->plr->y_p * 64);
		l->stock[l->plr->y_p][l->plr->x_p] = '0';
		l->plr->y_p = l->plr->y_p - 1;
		l->stock[l->plr->y_p][l->plr->x_p] = 'P';
		l->ss++;
		animation_player_bonus(l);
		animation_player_bonus(l);
	}
}
