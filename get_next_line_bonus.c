/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:25:08 by abouchfa          #+#    #+#             */
/*   Updated: 2021/11/17 13:53:58 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(void *p)
{
	if (p)
		free(p);
}

void	reset_buffer(char *buffer)
{
	size_t	l;
	size_t	i;

	l = 0;
	i = 0;
	while (buffer[l] != '\n' && buffer[l] != '\0')
		l++;
	while (buffer[l++])
		buffer[i++] = buffer[l];
	buffer[i] = 0;
}

char	*collect_line(char *line)
{
	int		len;
	char	*temp;

	if (!*line)
	{
		ft_free(line);
		return (NULL);
	}
	len = 0;
	while (*(line + len) != '\n' && *(line + len) != '\0')
		len++;
	if (*(line + len) == '\n')
		len++;
	temp = line;
	line = malloc (len + 1);
	ft_strncpy(line, temp, len);
	ft_free(temp);
	return (line);
}

char	*read_line(int fd, char *buffer)
{
	char	*temp;
	char	*line;
	int		res;

	res = 1;
	line = NULL;
	if (*buffer)
	{
		line = "\0";
		line = ft_strjoin(line, buffer);
	}
	while (!gnl_strchr(line) && res > 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		buffer[res] = 0;
		temp = line;
		if (!line)
			line = "\0";
		line = ft_strjoin(line, buffer);
		ft_free(temp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		stock[1024][BUFFER_SIZE + 1];
	char			*buffer;
	char			*line;

	if (fd < 0)
		return (NULL);
	buffer = stock[fd];
	line = read_line(fd, buffer);
	line = collect_line(line);
	reset_buffer(buffer);
	stock[fd][0] = *buffer;
	return (line);
}
