/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:59:56 by lgalstya          #+#    #+#             */
/*   Updated: 2022/04/21 14:23:53 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line_ret(char *line, int fd)
{
	char	current[BUFFER_SIZE + 1];
	long	i;

	while (1)
	{
		i = read(fd, current, BUFFER_SIZE);
		current[i] = '\0';
		if (i == -1)
			return (0);
		if (!line)
			line = ft_strdup(current);
		else
			line = ft_strjoin(line, current);
		if (ft_strchr(current, '\n') || i == 0)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		*line1;
	char		*line2;
	long		len;

	len = 0;
	buff[fd] = line_ret(buff[fd], fd);
	if (!buff[fd])
		return (0);
	len = ft_strlen(buff[fd]) - ft_strlen(ft_strchr(buff[fd], '\n')) + 1;
	line1 = ft_substr(buff[fd], 0, len);
	line2 = buff[fd];
	buff[fd] = ft_substr(buff[fd], len, ft_strlen(buff[fd]));
	free(line2);
	return (line1);
}
