/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:58:23 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 15:27:07 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_ber_bonus(int ac, char **av)
{
	int	j;
	int	k;

	j = 1;
	while (j < ac)
	{
		k = ft_strlen_bonus(av[j]) - 4;
		if (ft_strncmp_bonus(av[j] + k, ".ber", 4) != 0)
			erreur_bonus();
		j++;
	}
	return (1);
}

void	inis_bonus(t_list *m)
{
	m->s = 0;
	m->k = 0;
	m->countp = 0;
	m->counte = 0;
	m->countc = 0;
	m->countesp = 0;
	m->v = 0;
	m->i = 0;
	m->e = 0;
	m->t = 0;
	m->m = 0;
	m->ss = 0;
}

void	complet_cherch_bonus(t_list *m)
{
	m->k = 0;
	while (m->stock[m->s][m->k])
	{
		if (m->stock[m->s][m->k] == 'P')
		{
			m->p_player_y = m->s;
			m->p_player_x = m->k ;
			m->countp++;
		}
		if (m->stock[m->s][m->k] == 'E')
		{
			m->s1 = m->s;
			m->s2 = m->k;
			m->counte++;
		}
		if (m->stock[m->s][m->k] == 'C')
			m->countc++;
		if (m->stock[m->s][m->k] == ' ' || m->stock[m->s][m->k] == '\t')
			m->countesp++;
		m->k++;
	}
}

int	cherch_caracter_bonus(t_list *m)
{
	inis_bonus(m);
	while (m->stock[m->s])
	{
		m->k = 0;
		complet_cherch_bonus(m);
		m->s++;
	}
	if (m->countp != 1 || m->countc < 1 || m->counte != 1 || m->countesp != 0)
		erreur_bonus();
	return (1);
}

void	check_line_1_bonus(t_list *l)
{
	int	o;

	o = 0;
	while (l->stock[0][o])
	{
		if (l->stock[0][o] != '1')
			erreur_bonus();
		o++;
	}
	l->s = 0;
	l->e--;
	while (l->stock[l->e][l->s])
	{
		if (l->stock[l->e][l->s] != '1')
			erreur_bonus();
		l->s++;
	}
}
