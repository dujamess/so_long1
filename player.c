/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:16:47 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 15:45:59 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mouv_player_droit(t_list *l)
{
	if (l->stock[l->plr->y_p][l->plr->x_p + 1] == 'N')
		exit(0);
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
		putnber(l->ss);
		write(1, "\n", 1);
		mlx_put_image_to_window(l->mlx,
			l->mlx_win, l->w, l->plr->x_p * 64, l->plr->y_p * 64);
	}
}

void	mouv_player_gauch(t_list *l)
{
	if (l->stock[l->plr->y_p][l->plr->x_p - 1] == 'N')
		exit(0);
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
		putnber(l->ss);
		write(1, "\n", 1);
		l->stock[l->plr->y_p][l->plr->x_p] = 'P';
		mlx_put_image_to_window(l->mlx,
			l->mlx_win, l->inv_pl, l->plr->x_p * 64, l->plr->y_p * 64);
	}
}

void	mouv_player_haut(t_list *l)
{
	if (l->stock[l->plr->y_p + 1][l->plr->x_p] == 'N')
		exit(0);
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
		putnber(l->ss);
		write(1, "\n", 1);
		mlx_put_image_to_window(l->mlx,
			l->mlx_win, l->w, l->plr->x_p * 64, l->plr->y_p * 64);
	}
}

void	mouv_player_bas(t_list *l)
{
	if (l->stock[l->plr->y_p - 1][l->plr->x_p] == 'N')
		exit(0);
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
		putnber(l->ss);
		write(1, "\n", 1);
		mlx_put_image_to_window(l->mlx,
			l->mlx_win, l->w, l->plr->x_p * 64, l->plr->y_p * 64);
	}
}
