/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_enms_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:40:00 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 14:17:42 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	decalage_bonus(int c)
{
	while (c >= 0)
	{
		write(1, "", 1);
		c--;
	}
}

int	numbr_enm_bonus(t_list *l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	l->enemy->nbr_enm = 0;
	while (l->stock[i])
	{
		j = 0;
		while (l->stock[i][j])
		{
			if (l->stock[i][j] == 'N')
				l->enemy->nbr_enm++;
			j++;
		}
		i++;
	}
	return (l->enemy->nbr_enm);
}
