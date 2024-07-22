/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:21:49 by atangil           #+#    #+#             */
/*   Updated: 2024/01/09 17:04:20 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// *1 = wall;
// *0 = empty;
// *E = exit;
// In map, it starts checking from the start point (x, y), first it changes current tile with ".", 
// then it proceeds to check all other adjacent tiles if they are "E" or not, if it is, it changes it with ".".
// then it starts recurisive until it finds any 1's.

// in the end it changes all the adjacent tiles to "." that could be reached with horizontal and vertical movements from the start point.
// leavin unreachable tiles unmarked.
static void	is_logic_sub(char **map, int x, int y)
{
	map[x][y] = '.';
	if (map[x + 1][y] == 'E')
		map[x + 1][y] = '.';
	else if (map[x - 1][y] == 'E')
		map[x - 1][y] = '.';
	else if (map[x][y + 1] == 'E')
		map[x][y + 1] = '.';
	else if (map[x][y - 1] == 'E')
		map[x][y - 1] = '.';
	if (map[x + 1][y] == '0' || map[x + 1][y] == 'C')
		is_logic_sub(map, x + 1, y);
	if (map[x - 1][y] == '0' || map[x - 1][y] == 'C')
		is_logic_sub(map, x - 1, y);
	if (map[x][y + 1] == '0' || map[x][y + 1] == 'C')
		is_logic_sub(map, x, y + 1);
	if (map[x][y - 1] == '0' || map[x][y - 1] == 'C')
		is_logic_sub(map, x, y - 1);
}

// we marked all reachable tiles with "."s in the is_logic_sub function. so instead of the exit and coins, there should be only "."s if these
// objects are reachable.

// and this function checks all the tiles, as we know there shouldn't be any C's or E's, when its finds one, it returns "0". meaning that there
// is unreachable objects in the map bordered by walls
static int	check_logic(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// and lastly gathers and calls the all of the logic functions in order to check the final result.
int	is_logic(char **map)
{
	int	x;
	int	y;
	int	res;

	locate_player(map, &x, &y);
	is_logic_sub(map, x, y);
	res = check_logic(map);
	free_map(map);
	return (res);
}
