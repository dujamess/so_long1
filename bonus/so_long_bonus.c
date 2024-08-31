/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:15:14 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 15:32:01 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	double_map_bonus(t_list *l)
{
	int	i;
	int	x;

	l->double_maps = (char **)malloc(sizeof(char *) * (l->nbr_ling + 1));
	i = 0;
	x = 0;
	while (l->stock[i])
	{
		l->double_maps[x] = (char *)malloc((l->h) + 1);
		l->double_maps[x] = ft_strcpy_bonus(l->double_maps[x], l->stock[i]);
		i++;
		x++;
	}
	l->double_maps[x] = NULL;
}

int	*creat_arr_bonus(int i, int j, int size_line, int numbers_line)
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

void	inisial_flag_bonus(t_list *l)
{
	int	y;

	y = 0;
	while (y < numbr_enm_bonus(l))
	{
		l->enemy->ar[y].flag = 0;
		y++;
	}
}

void	complet_check_bonus(t_list *l)
{
	int		*arr;

	double_map_bonus(l);
	alpha_bonus(l);
	check_nbr_enms_bonus(l);
	arr = creat_arr_bonus(l->p_player_y,
			l->p_player_x, l->h, l->nbr_ling);
	flood_fill_bonus(l->double_maps, arr);
	if (rest_flood_fill_bonus(l) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	free(arr);
	inis_mlx_pointer_bonus(l);
	put_img_map_bonus(l);
	stock_enm_bonus(l);
	inisial_flag_bonus(l);
	alloc_array1_bonus(l);
	l->hh = 0;
	mlx_hook(l->mlx_win, 17, 0, ft_exit_bonus, 0);
	mlx_loop_hook(l->mlx, mouv_enmi_bonus, l);
	mlx_hook(l->mlx_win, 3, 1L << 1, mouve_p_bonus, l);
	mlx_loop(l->mlx);
}

int	main(int ac, char **av)
{
	t_list	*l;

	if (ac == 2)
	{
		l = malloc(sizeof(t_list));
		l->plr = malloc(sizeof(t_player));
		l->enemy = malloc(sizeof(t_enemy));
		inis_bonus(l);
		if (check_ber_bonus(ac, av) == 0)
			return (0);
		if (open_file_bonus(l, av) != 1)
			return (0);
		stock_map_bonus(l, av);
		check_line_1_bonus(l);
		if (cherch_caracter_bonus(l) != 1)
			return (0);
		l->ss = 0;
		complet_check_bonus(l);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
