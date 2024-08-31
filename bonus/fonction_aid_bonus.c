/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_aid_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:50:25 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 14:18:13 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strncmp_bonus(char *s1, char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (1);
	}
	return (0);
}

void	free_spit_bonus(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_calcul_bonus(long int n)
{
	int	i;

	i = 1;
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_bonus(int n)
{
	char		*str;
	int			j;
	long int	m;

	m = (long int)n;
	j = ft_calcul_bonus(m);
	str = malloc(sizeof(char) * (j) +1);
	if (!str)
		return (NULL);
	str[j] = '\0';
	j--;
	if (m == 0)
		str[0] = '0';
	if (m < 0)
	{
		str[0] = '-';
		m = m * -1;
	}
	while (m > 0 && j >= 0)
	{
		str[j--] = m % 10 + '0';
		m = m / 10;
	}
	return (str);
}

char	*ft_strcpy_bonus(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
