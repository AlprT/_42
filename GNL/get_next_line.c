/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:14:32 by ahyilmaz          #+#    #+#             */
/*   Updated: 2023/08/01 14:58:41 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_after_newline(char *str)
{
	char	*after_str;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	after_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!after_str)
		return (NULL);
	i++;
	j = 0;
	while (str[i + j] != '\0')
	{
		after_str[j] = str[j + i];
		j++;
	}
	after_str[j] = '\0';
	free(str);
	return (after_str);
}

char	*get_the_main_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_whole_line(int fd, char *str)
{
	char	*buff;
	int		controller;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	controller = 1;
	while (!ft_strchr(str, '\n') && controller != 0)
	{
		controller = read(fd, buff, BUFFER_SIZE);
		if (controller == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[controller] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*oneline;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_whole_line(fd, str);
	if (!str)
		return (NULL);
	oneline = get_the_main_line(str);
	str = get_after_newline(str);
	return (oneline);
}
