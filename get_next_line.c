/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:55:48 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/11/27 19:01:05 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *buff)
{
	char	*line;
	int		linelen;
	int		i;

	if (!buff || !buff[0])
		return (NULL);
	linelen = 0;
	while (buff[linelen] != '\0' && buff[linelen] != '\n')
		linelen++;
	line = malloc(sizeof(char) * (linelen + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (i < linelen)
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*readjust_buff(char *buff)
{
	char	*new_buff;
	int		i;
	int		j;

	if (!buff)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	new_buff = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!new_buff)
		return (free(buff), NULL);
	j = 0;
	while (buff[i])
		new_buff[j++] = buff[i++];
	new_buff[j] = '\0';
	free(buff);
	return (new_buff);
}

char	*read_to_buff(char *buff, int fd)
{
	char	*temp;
	char	*new_buff;
	int		bytes_read;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buff), free(temp), NULL);
		if (bytes_read == 0)
            break ;
		temp[bytes_read] = '\0';
		new_buff = ft_strjoin(buff, temp);
		free(buff);
		buff = new_buff;
		if (!buff)
			return (free(temp), NULL);
		if (ft_strchr(buff, '\n'))
			break ;		
	}
	return (free(temp), buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	//int			fdlen;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buff = read_to_buff(buff, fd);
	if (!buff)
		return (NULL);
	line = extract_line(buff);
	if (!line)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	buff = readjust_buff(buff);
	return (line);
}
