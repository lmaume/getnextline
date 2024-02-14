/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:02:30 by lmaume            #+#    #+#             */
/*   Updated: 2024/02/14 16:38:20 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != (char)c && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == (char)c)
		return (&s[i]);
	else
		return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_linelen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size != 0 && sizeof(dst) != 0)
	{
		while (src[i] != '\0')
		{
			if (i < size - 1)
			{
				dst[i] = src[i];
				j++;
			}
			i++;
		}
		dst[j] = '\0';
	}
	return (ft_strlen(src));
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	int				result;

	line = NULL;
	if (!buffer[0])
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (NULL);
	while (ft_strchr(buffer, '\n') == NULL)
	{
		line = ft_strjoin(line, buffer, ft_strlen(buffer));
		ft_bzero(buffer, BUFFER_SIZE);
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == 0)
			return (line);
		else if (result < 0)
		{
			free(line);
			return (NULL);
		}
	}
	line = ft_strjoin(line, buffer, ft_linelen(buffer));
	ft_memcpy(buffer, ft_strchr(buffer, '\n') + 1, \
		ft_strlen(ft_strchr(buffer, '\n')));
	return (line);
}
