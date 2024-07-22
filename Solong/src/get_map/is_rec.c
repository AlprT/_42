/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:21:36 by atangil           #+#    #+#             */
/*   Updated: 2024/01/09 18:47:38 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include <stdio.h>

// it counts both dimensions of the array and returns it,
// which gaves us the size of the map.

// note : it checks only the first row and collumn. So map must be rectangular to be true.
void	get_coor(char **map, int *w, int *h)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[0][x])
		x++;
	while (map[y])
		y++;
	*w = x;
	*h = y;
}

// when called, it increases the count of the passing argument (object)
// when is_last flag used, it finally checks if the number of the object obeys the rules of the project
int	cont_obj(char C, int is_last)
{
	static int	p = 0;
	static int	e = 0;
	static int	c = 0;

	if (C == 'P')
		p++;
	else if (C == 'E')
		e++;
	else if (C == 'C')
		c++;
	if (is_last == 1)
	{
		if (p != 1 || e != 1 || c < 1)
			return (0);
		return (1);
	}
	return (0);
}

// a function to shorten the function below, because of the stupid norm.
void	obj_check(void)
{
	if (!cont_obj('x', 1))
		ft_err("Missing objects in map");
}

// it iterates through map, when on the border tiles, it checks if its 1, if not it means there is a openning in map, prints error.
// then when it sees a object, it increases it with a function.
// if there is a unrecognizable objects, it prints an message and exits.
// lastle with every iteration of collums it checks the equality of it with the width of the map, if not, its not rectangle, prints error.
// lastly calls obj_check if objects are valid.
int	is_rec(char **map)
{
	int	width;
	int	height;
	int	i;
	int	j;

	get_coor(map, &width, &height);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((!i || i == height - 1 || !j || j == width - 1)
				&& map[i][j] != '1')
				ft_err("Walls missing");
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
				cont_obj(map[i][j], 0);
			else if (map[i][j] != '1' && map[i][j] != '0')
				ft_err("Unrecognizable object in map");
		}
		if (width != j)
			ft_err("Map is not rectangle");
	}
	obj_check();
	return (1);
}
