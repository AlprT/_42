/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:42:35 by atangil           #+#    #+#             */
/*   Updated: 2024/01/15 18:30:45 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include "../libft/libft.h"
#include <unistd.h>

// increases the step, then prints it.
void	print_step(t_data *data)
{
	data -> mov_num++;
	ft_putstr_fd("Step : ", 1);
	ft_putnbr_fd(data -> mov_num, 1);
	ft_putchar_fd('\n', 1);
}

// in every move function below, it first checks destination is exit and no coins left, if its true, it exits the game.
// then else if (when it is exit but there are still coins in the map) it returns and does nothing else.
// in the second statement :
//		it checks if the destination is not a wall, if its not:
//			decerases the coin number by one if dest is a coin,
//			prints our current step value
//			changes current tile by 0 and destination tile by P.
//			changes the coordinate of our ch in the system according to our movement way.
void	move_u(t_data *data, int x, int y)
{
	if (data -> map[x - 1][y] == 'E' && data -> coin_num == 0)
	{
		end_game(data);
		print_step(data);
		exit(1);
	}
	else if (data -> map[x - 1][y] == 'E')
		return ;
	if (data -> map[x - 1][y] != '1')
	{
		if (data -> map[x - 1][y] == 'C')
			data -> coin_num--;
		print_step(data);
		data -> map[x][y] = '0';
		data -> map[x - 1][y] = 'P';
		data -> ch_x--;
	}
}

void	move_d(t_data *data, int x, int y)
{
	if (data -> map[x + 1][y] == 'E' && data -> coin_num == 0)
	{
		print_step(data);
		end_game(data);
		exit(1);
	}
	else if (data -> map[x + 1][y] == 'E')
		return ;
	if (data -> map[x + 1][y] != '1')
	{
		if (data -> map[x + 1][y] == 'C')
			data -> coin_num--;
		print_step(data);
		data -> map[x][y] = '0';
		data -> map[x + 1][y] = 'P';
		data -> ch_x++;
	}
}

void	move_r(t_data *data, int x, int y)
{
	if (data -> map[x][y + 1] == 'E' && data -> coin_num == 0)
	{
		print_step(data);
		end_game(data);
		exit(1);
	}
	else if (data -> map[x][y + 1] == 'E')
		return ;
	if (data -> map[x][y + 1] != '1')
	{
		if (data -> map[x][y + 1] == 'C')
			data -> coin_num--;
		print_step(data);
		data -> map[x][y] = '0';
		data -> map[x][y + 1] = 'P';
		data -> ch_y++;
	}
}

void	move_l(t_data *data, int x, int y)
{
	if (data -> map[x][y - 1] == 'E' && data -> coin_num == 0)
	{
		print_step(data);
		end_game(data);
		exit(1);
	}
	else if (data -> map[x][y - 1] == 'E')
		return ;
	if (data -> map[x][y - 1] != '1')
	{
		if (data -> map[x][y - 1] == 'C')
			data -> coin_num--;
		print_step(data);
		data -> map[x][y] = '0';
		data -> map[x][y - 1] = 'P';
		data -> ch_y--;
	}
}
