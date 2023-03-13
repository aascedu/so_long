/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:05:04 by aascedu           #+#    #+#             */
/*   Updated: 2022/12/05 15:53:28 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line_fd(int fd)
{
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1] = {{0}};
	char		*line;
	int			byte_read;

	if (fd < 0)
		return (NULL);
	if (fd > OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, NULL, 0) != 0)
		return (ft_bzero(buff[fd], BUFFER_SIZE), NULL);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	*line = 0;
	byte_read = 1;
	if (!buff[fd][0])
		byte_read = read(fd, buff[fd], BUFFER_SIZE);
	if (byte_read <= 0)
		return (free(line), NULL);
	while (byte_read)
	{
		if (ft_newline(buff[fd]))
			return (add_buffer(line, buff[fd]));
		line = add_buffer(line, buff[fd]);
		byte_read = read(fd, buff[fd], BUFFER_SIZE);
	}
	return (add_buffer(line, buff[fd]));
}
