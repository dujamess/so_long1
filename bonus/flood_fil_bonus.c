/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:30:25 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 14:48:45 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill_bonus(char **stock, int *arr)
{
	if (arr[0] < 0 || arr[0] >= arr[3] || arr[1] < 0 || arr[1] >= arr[2])
		return ;
	if (stock[arr[0]][arr[1]] == '1' || stock[arr[0]][arr[1]] == 'E'
		|| stock[arr[0]][arr[1]] == 't' || stock[arr[0]][arr[1]] == 'N')
		return ;
	stock[arr[0]][arr[1]] = 't';
	arr[0] += 1;
	flood_fill_bonus(stock, arr);
	arr[0] -= 2;
	flood_fill_bonus(stock, arr);
	arr[0] += 1;
	arr[1] += 1;
	flood_fill_bonus(stock, arr);
	arr[1] -= 2;
	flood_fill_bonus(stock, arr);
	arr[1] += 1;
}

void	check_flood_bonus(t_list *l, t_i *i)
{
	while (l->double_maps[i->x][i->i])
	{
		if (l->double_maps[i->x][i->i] == 'C')
			i->c++;
		if (l->double_maps[i->x][i->i] == 'E')
		{
			i->m = i->x;
			i->n = i->i;
		}
		i->i++;
	}
}

void	inisalisation_variable_bonus(t_i *i)
{
	i->x = 0;
	i->c = 0;
	i->i = 0;
	i->m = 0;
	i->n = 0;
}

int	rest_flood_fill_bonus(t_list *l)
{
	t_i	*i;

	i = malloc(sizeof(t_i));
	inisalisation_variable_bonus(i);
	while (l->double_maps[i->x])
	{
		i->i = 0;
		check_flood_bonus(l, i);
		i->x++;
	}
	if (i->c != 0)
	{
		free(i);
		return (0);
	}
	if (l->double_maps[i->m][i->n + 1] == 't'
		|| l->double_maps[i->m][i->n - 1] == 't'
		|| l->double_maps[i->m + 1][i->n] == 't'
		|| l->double_maps[i->m - 1][i->n] == 't')
	{
		free(i);
		return (1);
	}
	free(i);
	return (0);
}

int	chec_alpha_bonus(t_list *l)
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
				&& l->double_maps[i][j] != 'E' && l->double_maps[i][j] != 'N')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
