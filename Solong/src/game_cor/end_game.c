/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:52:12 by atangil           #+#    #+#             */
/*   Updated: 2024/01/14 18:32:04 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../../inc/so_long.h"
#include <stdlib.h>

// frees everything we decelared, to make the program ready to exit without any leaks. "!!" operator makes it bool.

void	end_game(t_data *data)
{
	if (!!data -> map)
		free_map(data -> map);
	if (!!data -> ch)
		mlx_destroy_image(data -> mlx, data -> ch);
	if (!!data -> wall)
		mlx_destroy_image(data -> mlx, data -> wall);
	if (!!data -> ground)
		mlx_destroy_image(data -> mlx, data -> ground);
	if (!!data -> coin)
		mlx_destroy_image(data -> mlx, data -> coin);
	if (!!data -> exit)
		mlx_destroy_image(data -> mlx, data -> exit);
	if (!!data -> mlx_win)
		mlx_destroy_window(data -> mlx, data -> mlx_win);
	if (!!data)
		free(data);
}
