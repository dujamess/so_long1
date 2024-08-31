/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:15:14 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 15:18:22 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	double_map(t_list *l)
{
	int	i;
	int	x;

	l->double_maps = (char **)malloc(sizeof(char *) * (l->nbr_ling + 1));
	i = 0;
	x = 0;
	while (l->stock[i])
	{
		l->double_maps[x] = (char *)malloc((l->h) + 1);
		l->double_maps[x] = ft_strcpy(l->double_maps[x], l->stock[i]);
		i++;
		x++;
	}
	l->double_maps[x] = NULL;
}

int	*creat_arr(int i, int j, int size_line, int numbers_line)
{
	int	*arr;

	arr = malloc(sizeof(int) * 4);
	if (arr == NULL)
		return (NULL);
	arr[0] = i;
	arr[1] = j;
	arr[2] = size_line;
	arr[3] = numbers_line;
	return (arr);
}

void	alpha(t_list *l)
{
	if (chec_alpha(l) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	complet_check(t_list *l)
{
	int		*arr;

	double_map(l);
	alpha(l);
	arr = creat_arr(l->p_player_y,
			l->p_player_x, l->h, l->nbr_ling);
	flood_fill(l->double_maps, arr);
	if (rest_flood_fill(l) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	free(arr);
	inis_mlx_pointer(l);
	put_img_map(l);
	l->hh = 0;
	mlx_hook(l->mlx_win, 17, 0, ft_exit, 0);
	mlx_hook(l->mlx_win, 2, 1L << 0, mouve_p, l);
	mlx_loop(l->mlx);
}

int	main(int ac, char **av)
{
	t_list	*l;

	if (ac == 2)
	{
		l = malloc(sizeof(t_list));
		l->plr = malloc(sizeof(t_player));
		l->plr->y_p = 0;
		l->plr->x_p = 0;
		inis(l);
		if (check_ber(ac, av) == 0)
			return (0);
		if (open_file(l, av) != 1)
			return (0);
		stock_map(l, av);
		check_line_1(l);
		if (cherch_caracter(l) != 1)
			return (0);
		l->ss = 0;
		complet_check(l);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
