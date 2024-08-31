/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:30:25 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 14:16:56 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **stock, int *arr)
{
	if (arr[0] < 0 || arr[0] >= arr[3] || arr[1] < 0 || arr[1] >= arr[2])
		return ;
	if (stock[arr[0]][arr[1]] == '1' || stock[arr[0]][arr[1]] == 'E'
		|| stock[arr[0]][arr[1]] == 't')
		return ;
	stock[arr[0]][arr[1]] = 't';
	arr[0] += 1;
	flood_fill(stock, arr);
	arr[0] -= 2;
	flood_fill(stock, arr);
	arr[0] += 1;
	arr[1] += 1;
	flood_fill(stock, arr);
	arr[1] -= 2;
	flood_fill(stock, arr);
	arr[1] += 1;
}

void	check_flood(t_list *l, t_i *i)
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

void	inisalisation_variable(t_i *i)
{
	i->x = 0;
	i->c = 0;
	i->i = 0;
	i->m = 0;
	i->n = 0;
}

int	rest_flood_fill(t_list *l)
{
	t_i	*i;

	i = malloc(sizeof(t_i));
	inisalisation_variable(i);
	while (l->double_maps[i->x])
	{
		i->i = 0;
		check_flood(l, i);
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
