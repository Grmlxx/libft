/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:04:19 by alamaoui          #+#    #+#             */
/*   Updated: 2023/12/31 02:11:00 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_fd(int fd, char *line)
{
	char	*buff;
	ssize_t	counter;

	counter = 1;
	buff = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchr(line, '\n') && counter > 0)
	{
		counter = read(fd, buff, BUFFER_SIZE);
		if (counter == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[counter] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

static char	*c_first_part(char *line)
{
	int	i;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	return (ft_substr(line, 0, i + 1));
}

static char	*c_remaining_part(char *line)
{
	char	*str;
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = ft_substr(line + i + 1, 0, ft_strlen(line) - i + 1);
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*current;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	line[fd] = read_fd(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	current = c_first_part(line[fd]);
	line[fd] = c_remaining_part(line[fd]);
	return (current);
}
