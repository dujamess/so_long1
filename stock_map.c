/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:05:18 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 15:18:38 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	erreur(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	open_file(t_list *m, char **av)
{
	m->fd = open(av[1], O_RDONLY);
	if (!m->fd)
		return (0);
	m->line = get_next_line(m->fd);
	if (!m->line)
	{
		free(m->plr);
		close(m->fd);
		free(m);
		write(1, "Error\n", 6);
		return (0);
	}
	while (m->line)
	{
		free(m->line);
		m->line = get_next_line(m->fd);
		m->v++;
	}
	m->stock = (char **)malloc(sizeof(char *) * (m->v + 1));
	close(m->fd);
	return (1);
}

void	alocation_map(t_list *l, int y)
{
	l->h = 0;
	l->stock[l->i] = (char *)malloc(ft_strlen(l->line1) + 1);
	y = ft_strlen(l->line1);
	if (l->line1[l->h] == '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (l->line1[l->h])
	{
		if (l->line1[0] != '1')
			erreur();
		l->stock[l->i][l->h] = l->line1[l->h];
		l->h++;
	}
	l->stock[l->i][l->h] = '\0';
	if (l->line1[l->h] || l->line1[l->h -1] != '1')
		erreur();
	free(l->line1);
	l->line1 = get_next_line(l->fd);
	l->e++;
	l->i++;
	if (ft_strlen(l->line1) != y && l->line1)
		erreur();
}

void	stock_map(t_list *l, char **av)
{
	int	y;

	inis(l);
	y = 0;
	l->nbr_ling = 0;
	l->fd = open(av[1], O_RDONLY);
	l->line1 = get_next_line(l->fd);
	while (l->line1)
		alocation_map(l, y);
	l->nbr_ling = l->i;
	l->stock[l->i] = NULL;
	close(l->fd);
}

int	chec_alpha(t_list *l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (l->double_maps[i])
	{
		j = 0;
		while (l->double_maps[i][j])
		{
			if (l->double_maps[i][j] != '1' && l->double_maps[i][j] != '0'
				&& l->double_maps[i][j] != 'P' && l->double_maps[i][j] != 'C'
				&& l->double_maps[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
