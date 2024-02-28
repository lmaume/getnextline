/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:01:42 by lmaume            #+#    #+#             */
/*   Updated: 2024/02/28 18:00:01 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
size_t	ft_linelen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2, size_t len);
char	*ft_strchr(char *s, int c);
char	*ft_strldup(char *s, size_t len);

#endif
