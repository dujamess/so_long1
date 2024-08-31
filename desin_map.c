/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desin_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:08:11 by khmessah          #+#    #+#             */
/*   Updated: 2024/08/31 17:12:23 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	complet_protect(t_list *l)
{
	l->exit = "./porte.xpm";
	l->f = mlx_xpm_file_to_image(l->mlx, l->exit, &l->img_w, &l->img_h);
	l->port_over = "./port_ouvert.xpm";
	l->pov = mlx_xpm_file_to_image(l->mlx, l->port_over, &l->img_w, &l->img_h);
	l->enm = "./enm.xpm";
	l->en = mlx_xpm_file_to_image(l->mlx, l->enm, &l->img_w, &l->img_h);
	l->game = "./game.xpm";
	l->gam = mlx_xpm_file_to_image(l->mlx, l->game, &l->img_w, &l->img_h);
	l->crono = "./crono.xpm";
	l->cro = mlx_xpm_file_to_image(l->mlx, l->crono, &l->img_w, &l->img_h);
	l->inv_player = "./inv_player.xpm";
	l->inv_pl = mlx_xpm_file_to_image(l->mlx,
			l->inv_player, &l->img_w, &l->img_h);
	if (!l->cro ||!l->gam || !l->mlx || !l->pov || !l->f
		|| !l->b || !l->w || !l->p || !l->img
		|| !l->mlx_win || !l->en || !l->inv_pl)
		exit(1);
}

void	inis_mlx_pointer(t_list *l)
{
	l->mlx = mlx_init();
	l->mlx_win = mlx_new_window(l->mlx, l->h * 64, l->s * 64, "duva");
}

void	complex_put_img(t_list *l)
{
	if (l->stock[l->t][l->m] && l->stock[l->t][l->m] == 'P')
	{
		l->plr->y_p = l->t;
		l->plr->x_p = l->m;
		mlx_put_image_to_window(l->mlx,
			l->mlx_win, l->w, l->m * 64, l->t * 64);
	}
	if (l->stock[l->t][l->m] && l->stock[l->t][l->m] == 'C')
		mlx_put_image_to_window(l->mlx,
			l->mlx_win, l->b, l->m * 64, l->t * 64);
	if (l->stock[l->t][l->m] && l->stock[l->t][l->m] == 'E')
		mlx_put_image_to_window(l->mlx,
			l->mlx_win, l->f, l->m * 64, l->t * 64);
}

void	put_img_map(t_list *l)
{
	while (l->t < l->s)
	{
		l->m = 0;
		while (l->m < l->h)
		{
			mlx_put_image_to_window(l->mlx,
				l->mlx_win, l->img, l->m * 64, l->t * 64);
			if (l->stock[l->t][l->m] && l->stock[l->t][l->m] == '1')
				mlx_put_image_to_window(l->mlx,
					l->mlx_win, l->p, l->m * 64, l->t * 64);
			complex_put_img(l);
			l->m++;
		}
		l->t++;
	}
}
