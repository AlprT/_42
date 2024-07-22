/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:16:43 by atangil           #+#    #+#             */
/*   Updated: 2024/01/15 18:33:04 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include "../minilibx/mlx.h"

// when called, it puts all the images to the window depending on our map, it amplifies it by SIZE because its our maps original object size.
void	image_init(t_data *data, void *image, int i, int j)
{
	mlx_put_image_to_window(data -> mlx, data -> mlx_win, image,
		j * SIZE, i * SIZE);
}

void	put_image(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data -> map[i])
	{
		j = 0;
		while (data -> map[i][j])
		{
			if (data -> map[i][j] == '1')
				image_init(data, data -> wall, i, j);
			if (data -> map[i][j] == '0')
				image_init(data, data -> ground, i, j);
			if (data -> map[i][j] == 'P')
				image_init(data, data -> ch, i, j);
			if (data -> map[i][j] == 'E')
				image_init(data, data -> exit, i, j);
			if (data -> map[i][j] == 'C')
				image_init(data, data -> coin, i, j);
			j++;
		}
		i++;
	}
}
