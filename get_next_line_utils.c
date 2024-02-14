/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:00:00 by lmaume            #+#    #+#             */
/*   Updated: 2024/02/14 16:36:41 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *s)
{
	char	*s2;

	s2 = malloc(ft_strlen(s) + 1);
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, s, ft_strlen(s) + 1);
	return (s2);
}

static
char	*protec_join(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	return (ft_strdup(s2));
}

char	*ft_strjoin(char *s1, char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1 || !s2)
		return (protec_join(s1, s2));
	i = 0;
	j = 0;
	ret = malloc(ft_strlen(s1) + len + 2);
	if (!ret)
		return (NULL);
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && j <= len)
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	free(s1);
	return (ret);
}
