/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:05:18 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 15:32:27 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	erreur_bonus(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	open_file_bonus(t_list *m, char **av)
{
	m->fd = open(av[1], O_RDONLY);
	if (!m->fd)
		return (0);
	m->line = get_next_line_bonus(m->fd);
	if (!m->line)
	{
		free(m->plr);
		free(m->enemy);
		close(m->fd);
		free(m);
		write(1, "Error\n", 6);
		return (0);
	}
	while (m->line)
	{
		free(m->line);
		m->line = get_next_line_bonus(m->fd);
		m->v++;
	}
	m->stock = (char **)malloc(sizeof(char *) * (m->v + 1));
	close(m->fd);
	return (1);
}

void	alocation_map_bonus(t_list *l, int y)
{
	l->h = 0;
	l->stock[l->i] = (char *)malloc(ft_strlen_bonus(l->line1) + 1);
	y = ft_strlen_bonus(l->line1);
	if (l->line1[l->h] == '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (l->line1[l->h])
	{
		if (l->line1[0] != '1')
			erreur_bonus();
		l->stock[l->i][l->h] = l->line1[l->h];
		l->h++;
	}
	l->stock[l->i][l->h] = '\0';
	if (l->line1[l->h] || l->line1[l->h -1] != '1')
		erreur_bonus();
	free(l->line1);
	l->line1 = get_next_line_bonus(l->fd);
	l->e++;
	l->i++;
	if (ft_strlen_bonus(l->line1) != y && l->line1)
		erreur_bonus();
}

void	stock_map_bonus(t_list *l, char **av)
{
	int	y;

	inis_bonus(l);
	y = 0;
	l->nbr_ling = 0;
	l->fd = open(av[1], O_RDONLY);
	l->line1 = get_next_line_bonus(l->fd);
	while (l->line1)
		alocation_map_bonus(l, y);
	l->nbr_ling = l->i;
	l->stock[l->i] = NULL;
	close(l->fd);
}
