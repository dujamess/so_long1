/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appel_fonction_mouv_player.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:57:28 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 15:45:32 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mouv_player_2(t_list *l, int c)
{
	if (l->countc == 0)
		mlx_put_image_to_window(l->mlx,
			l->mlx_win, l->pov, l->s2 * 64, l->s1 * 64);
	if (c == 100)
		mouv_player_droit(l);
	else if (c == 119)
		mouv_player_bas(l);
}

void	putnber(int c)
{
	if (c > 9)
		putnber(c / 10);
	write(1, &"0123456789"[c % 10], 1);
}

int	mouve_p(int c, t_list *l)
{
	mouv_player_2(l, c);
	if (c == 97)
		mouv_player_gauch(l);
	else if (c == 115)
		mouv_player_haut(l);
	else if (c == 65307)
		exit(0);
	return (0);
}

int	ft_exit(int c, void *param)
{
	(void)param;
	(void)c;
	exit(0);
}
