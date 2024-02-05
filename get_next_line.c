/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:02:30 by lmaume            #+#    #+#             */
/*   Updated: 2024/02/05 17:31:40 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];		// *ce qui est lu va dans buffer
	static char		*stock = NULL;					// **ce qui a fini d'etre lu est save dans le stock
	char*			line;							// ***la ligne a rendre va dans line
	int				i;
	
	i = 0;
	line = NULL;
	while (ft_strchr(buffer, '\n') == NULL)			// TODO :boucler jusqua la fin de la ligne (fait crash w/ any condition, why?)
	{
		if (read(fd, buffer, BUFFER_SIZE) < 0)		// *ce qui est lu va dans buffer
			return (NULL);							// toujours return NULL si erreur ou fin
		//stock = buffer;							// **ce qui a fini d'etre lu est save dans le stock
		line = ft_strjoin(line, buffer);			// ***la ligne a rendre va dans line
	}
	stock = ft_strchr(stock, '\n');					// ?(tentative de l'enlever du stock)
	//	 line = ft_strjoin(stock, buffer);
	return(line);
}
