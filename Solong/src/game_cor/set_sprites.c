/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:41:48 by atangil           #+#    #+#             */
/*   Updated: 2024/01/14 18:14:31 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../../inc/so_long.h"
#include "../libft/libft.h"

// it assigns our xpm files to pointers to let us use them
// mlx_xpm_file_to_image function converts xpm files to images and returns their adresses

void	set_sprites(t_data *data)
{
	int	i;
	int	j;

	data -> ch = mlx_xpm_file_to_image(data -> mlx,
			"./src/sprites/ch.xpm", &i, &j);
	data -> ground = mlx_xpm_file_to_image(data -> mlx,
			"./src/sprites/ground.xpm", &i, &j);
	data -> wall = mlx_xpm_file_to_image(data -> mlx,
			"./src/sprites/wall.xpm", &i, &j);
	data -> coin = mlx_xpm_file_to_image(data -> mlx,
			"./src/sprites/coin.xpm", &i, &j);
	data -> exit = mlx_xpm_file_to_image(data -> mlx,
			"./src/sprites/exit.xpm", &i, &j);
	if (!data -> ch || !data -> ground
		|| !data -> wall || !data -> coin || !data -> exit)
	{
		end_game(data);
		ft_err("xpm error");
	}
	data -> character = data -> ch;
}
