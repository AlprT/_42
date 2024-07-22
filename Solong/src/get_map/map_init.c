/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:52:07 by atangil           #+#    #+#             */
/*   Updated: 2024/01/10 17:00:49 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// free, close, print error, and exit.
static void	ex(int fd, char *line, char *map_path)
{
	free(map_path);
	if (line)
		free (line);
	close (fd);
	ft_err("Issues while reading file");
}

// first opens the map from the path,
// then reads 1 char from it and puts a null terminator of it, (because we read 1 and after that we put a null, when we declare the array we use 2 as size)
// then we iterate in the file char by char, we first read it, then join it to our other char, and at the and we got our map.
// then closes and returns the map.
static char	*read_map(char *map_path)
{
	int		fd;
	int		i;
	char	line[2];
	char	*join;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = read(fd, line, 1);
	line[i] = '\0';
	join = NULL;
	while (i)
	{
		join = ft_strjoin(join, line);
		if (!join)
			ex(fd, line, map_path);
		i = read(fd, line, 1);
		line[i] = '\0';
	}
	return (close(fd), join);
}

// we read the map and split it from newlines and assigns the 2 dimensional array to referanced map arrays,
// if some issues occur, frees and exits.
static void	create_map(char *map_path, char ***map1, char ***map2)
{
	char	*map;

	map = read_map(map_path);
	if (!map)
		ft_err("File could not be read");
	*map1 = ft_split(map, '\n');
	if (!(*map1))
	{
		free(map);
		ft_err("File could not be read");
	}
	*map2 = ft_split(map, '\n');
	if (!(*map2))
	{
		free(map);
		free_map(*map1);
		ft_err("File could not be read");
	}
	free(map);
}

// first checks the file type
// then it creates 2 same maps by the passing folder path
// after;
//		first it checks if its rectangle with one map,
//		then it checks if the map is logic (we change the map inside the logic process, so we can't use it again, thats why we need 2 copies of the map)
char	**map_init(char *map_path)
{
	char	**map;
	char	**map_cpy;

	if (!is_ber(map_path))
		ft_err("Invalid file type");
	create_map(map_path, &map, &map_cpy);
	if (!is_rec(map))
	{
		free_map(map);
		free_map(map_cpy);
		ft_err("Map isn't rectangular.");
	}
	if (!is_logic(map_cpy))
	{
		free_map(map);
		ft_err("Game is not logic");
	}
	return (map);
}
