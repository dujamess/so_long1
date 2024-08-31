/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:38:41 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 14:16:49 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_update(char *counter)
{
	int		i;
	char	*s2;
	int		j;

	i = 0;
	if (!counter)
		return (NULL);
	while (counter[i] && counter[i] != '\n')
		i++;
	if (counter[i] == '\n')
		i++;
	s2 = malloc(ft_strlen(counter) - i + 1);
	if (!s2)
		return (free(counter), NULL);
	j = 0;
	while (counter && counter[i])
		s2[j++] = counter[i++];
	s2[j] = '\0';
	free(counter);
	return (s2);
}

char	*return_ligne(char *counter, char *str)
{
	int	i;

	i = 0;
	if (counter[i] && counter[i] != '\n')
	{
		while (counter[i] && counter[i] != '\n')
		{
			str[i] = counter[i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char			*str;
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	str = malloc(i + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_line(char *counter)
{
	int		i;
	char	*str;

	i = 0;
	if (!counter || counter[i] == '\0')
		return (NULL);
	if (counter[i] == '\n')
	{
		i++;
		if (counter[i] == '\0')
			return (ft_strdup("\n"));
	}
	while (counter[i] && counter[i] != '\n')
		i++;
	if (counter[i] == '\n')
		i++;
	str = malloc(i + 1);
	if (!str || !counter)
		return (NULL);
	str = return_ligne(counter, str);
	return (str);
}
