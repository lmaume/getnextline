/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:00:00 by lmaume            #+#    #+#             */
/*   Updated: 2024/02/05 17:30:59 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	endfinder(char* str)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (j == 0 && str[i] != '\0')
	{
		if(str[i] == '\n')
			j = 1;
		i++;
	}
		
	return (j);
}

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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	i = 0;
	j = 0;
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}
