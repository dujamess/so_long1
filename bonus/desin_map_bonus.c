/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desin_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:08:11 by khmessah          #+#    #+#             */
/*   Updated: 2024/08/31 17:19:22 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	complet_protect_bonus(t_list *l)
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

void	inis_mlx_pointer_bonus(t_list *l)
{
	l->mlx = mlx_init();
	l->mlx_win = mlx_new_window(l->mlx, l->h * 64, l->s * 64, "duva");
	l->relative_path = "./lwast.xpm";
	l->r = "./www.xpm";
	l->lfo9 = "./kharof.xpm";
	l->img = mlx_xpm_file_to_image(l->mlx,
			l->relative_path, &l->img_w, &l->img_h);
	l->p = mlx_xpm_file_to_image(l->mlx, l->r, &l->img_w, &l->img_h);
	l->w = mlx_xpm_file_to_image(l->mlx, l->lfo9, &l->img_w, &l->img_h);
	l->col = "./fiter.xpm";
	l->b = mlx_xpm_file_to_image(l->mlx, l->col, &l->img_w, &l->img_h);
	complet_protect_bonus(l);
}

void	complex_put_img_bonus(t_list *l)
{
	int	i;

	i = 0;
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
	if (l->stock[l->t][l->m] && l->stock[l->t][l->m] == 'N')
	{
		l->yy = l->m;
		l->y1 = l->t;
		l->enemy->ar_pos[i] = l->yy;
		i++;
		mlx_put_image_to_window(l->mlx,
			l->mlx_win, l->en, l->m * 64, l->t * 64);
	}
}

void	put_img_map_bonus(t_list *l)
{
	l->enemy->ar_pos = malloc(sizeof(int) * numbr_enm_bonus(l));
	while (l->t < l->s)
	{
		l->m = 0;
		while (l->m < l->h)
		{
			mlx_put_image_to_window(l->mlx,
				l->mlx_win, l->img, l->m * 64, l->t * 64);
			mlx_put_image_to_window(l->mlx, l->mlx_win, l->gam, 0 * 64, 0 * 64);
			mlx_put_image_to_window(l->mlx,
				l->mlx_win, l->cro, (l->h - 1) * 64, 0 * 64);
			if (l->stock[l->t][l->m] && l->stock[l->t][l->m] == '1')
				mlx_put_image_to_window(l->mlx,
					l->mlx_win, l->p, l->m * 64, l->t * 64);
			complex_put_img_bonus(l);
			l->m++;
		}
		l->t++;
	}
}

void	check_nbr_enms_bonus(t_list *l)
{
	int	j;
	int	i;
	int	n;

	j = 0;
	i = 0;
	n = 0;
	while (l->double_maps[i])
	{
		j = 0;
		while (l->double_maps[i][j])
		{
			if (l->double_maps[i][j] == 'N')
				n++;
			j++;
		}
		i++;
	}
	if (n == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
