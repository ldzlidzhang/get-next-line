/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:27:45 by lidzhang          #+#    #+#             */
/*   Updated: 2022/11/16 13:39:24 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest_str;
	char		*line_buff;
	int			len;

	if (fd < 0)
		return (NULL);
	line_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	len = 1;
	while (!ft_strchr(rest_str, '\n') && len != 0 && line_buff)
	{
		len = read(fd, line_buff, BUFFER_SIZE);
		if (len == -1)
		{
			free(line_buff);
			return (NULL);
		}
		line_buff[len] = '\0';
		rest_str = ft_strjoin(rest_str, line_buff);
	}
	free (line_buff);
	line_buff = extract_line(rest_str);
	rest_str = extract_rest(rest_str);
	return (line_buff);
}
