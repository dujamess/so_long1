/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:26:03 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 14:17:48 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	alloc_array1_bonus(t_list *l)
{
	l->arr1 = malloc(sizeof(char *) * 2);
	l->arr2 = malloc(sizeof(char *) * 2);
}

void	animation_player_bonus(t_list *l)
{
	int		z;

	l->close_bouch = "./player_close.xpm";
	l->close = mlx_xpm_file_to_image(l->mlx,
			l->close_bouch, &l->img_w, &l->img_h);
	l->arr1[0] = l->close;
	l->arr1[1] = l->w;
	z = 0;
	if (l->hh < 2)
	{
		z = 1000 * 20;
		mlx_put_image_to_window(l->mlx, l->mlx_win,
			l->arr1[l->hh], l->plr->x_p * 64, l->plr->y_p * 64);
		while (z > 0)
		{
			write(1, "", 1);
			z--;
		}
		l->hh++;
		if (l->hh >= 2)
			l->hh = 0;
	}
	mlx_destroy_image(l->mlx, l->close);
}

void	animation_player_inverse_bonus(t_list *l)
{
	int		z;

	l->close_bouch = "./player_close.xpm";
	l->close = mlx_xpm_file_to_image(l->mlx,
			l->close_bouch, &l->img_w, &l->img_h);
	l->arr2[0] = l->close;
	l->arr2[1] = l->inv_pl;
	z = 0;
	if (l->hh < 2)
	{
		z = 1000 * 20;
		mlx_put_image_to_window(l->mlx, l->mlx_win,
			l->arr2[l->hh], l->plr->x_p * 64, l->plr->y_p * 64);
		while (z > 0)
		{
			write(1, "", 1);
			z--;
		}
		l->hh++;
		if (l->hh >= 2)
			l->hh = 0;
	}
	mlx_destroy_image(l->mlx, l->close);
}
