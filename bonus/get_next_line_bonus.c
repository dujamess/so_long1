/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:38:54 by khmessah          #+#    #+#             */
/*   Updated: 2024/03/18 14:18:10 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strchr_bonus(char *s, int c)
{
	int	i;

	c = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return (1);
		}
		i++;
	}
	if (c == '\0')
		return (0);
	return (0);
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	some;
	char			*s3;

	i = 0;
	j = 0;
	k = 0;
	if (!s2)
		return (NULL);
	some = ft_strlen_bonus(s1) + ft_strlen_bonus(s2);
	s3 = malloc(sizeof(char) * (some +1));
	if (!s3)
		return (NULL);
	while (s1 && s1[i] && i < some)
		s3[j++] = (char)s1[i++];
	while (s2[k] && j < some)
		s3[j++] = (char)s2[k++];
	s3[j] = '\0';
	return (free(s1), s3);
}

char	*read_get_bonus(char *counter, int fd)
{
	char		*buf;
	ssize_t		l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE * sizeof (char) + 1);
	if (!buf)
		return (NULL);
	l = 1;
	while (l > 0)
	{
		l = read(fd, buf, BUFFER_SIZE);
		if (l <= 0)
			break ;
		buf[l] = '\0';
		counter = ft_strjoin_bonus(counter, buf);
		if (ft_strchr_bonus(counter, '\n') == 1)
			break ;
	}
	if (l < 0 && counter)
		return (free(counter), NULL);
	else if (l < 0 && !counter)
		return (free(buf), NULL);
	return (free(buf), counter);
}

char	*get_next_line_bonus(int fd)
{
	static char	*counter;
	char		*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	counter = read_get_bonus(counter, fd);
	if (!counter)
		return (NULL);
	line = ft_line_bonus(counter);
	if (!line)
		return (NULL);
	counter = ft_update_bonus(counter);
	if (!*counter)
	{
		free(counter);
		counter = NULL;
	}
	return (line);
}
