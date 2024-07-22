/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:01:47 by atangil           #+#    #+#             */
/*   Updated: 2024/01/15 18:26:12 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

// when called, it first checks if our keycode is 53 (esc) or not. if it is true it exits the game.
// then changes mov member of our struct with the keycode, to let us use it after.
int	key_press(int key_id, t_data *data)
{
	if (key_id == 53)
	{
		end_game(data);
		exit(1);
	}
	data -> mov = key_id;
	return (0);
}

// when called it makes mov code by -1 making player stop
int	key_release(int key_id, t_data *data)
{
	(void)key_id;
	data -> mov = -1;
	return (0);
}

// when called exits the game
int	exit_game(t_data *data)
{
	end_game(data);
	exit(1);
	return (0);
}

// the function we call in every frame, it checks the mov code and calls the move function depending on the key code
// after that clears the window and puts images again to make the window change as we move in the game.

// frames by second could be very high because of our computers performance, it could affects our movement by making it very very fast
// so in every call we increase speed 1000 times to make the function work a little bit slower to prevent it by going too fast.
int	render_frame(t_data *data)
{
	int	x;
	int	y;

	if (data -> spd != 1000)
	{
		data -> spd++;
		return (0);
	}
	x = data -> ch_x;
	y = data -> ch_y;
	if (data -> mov == 2)
		move_r(data, x, y);
	else if (data -> mov == 0)
		move_l(data, x, y);
	else if (data -> mov == 1)
		move_d(data, x, y);
	else if (data -> mov == 13)
		move_u(data, x, y);
	data -> spd = 0;
	mlx_clear_window(data -> mlx, data -> mlx_win);
	put_image(data);
	return (0);
}

// we first allocate memory for our struct and everything else in it
// then we get the size of the map and save it in struct
// then we count the couins and save it in struct
// then we take the coordinates of the char "P" to set the player coordinates
// then we initilize our mlx library with mlx_init
// then we set our window and name its title with mlx_new_window
// we set the speed by 0, mov_num by 0, and mov by -1 to use it on other functions.
// then we get all adresses of the xpm sprites to use
void	so_long(char **map)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (free_map(map), ft_err("Malloc error"));
	data -> map = map;
	get_coor(map, &data -> map_w, &data -> map_h);
	data -> coin_num = count_coins(map);
	set_player(map, &data -> ch_x, &data -> ch_y);
	data -> mlx = mlx_init();
	if (!data -> mlx)
		return (free_map(map), free(data), ft_err("Mlx issue"));
	data -> mlx_win = mlx_new_window(data -> mlx, SIZE * data -> map_w, \
		SIZE * data -> map_h, "WOOO!");
	if (!data -> mlx_win)
		return (free_map(map), free(data), ft_err("Mlx_win issue"));
	data -> spd = 0;
	data -> mov_num = 0;
	data -> mov = -1;
	set_sprites(data);
	mlx_hook(data -> mlx_win, 02, (1L << 0), key_press, data);
	mlx_hook(data -> mlx_win, 03, (1L << 1), key_release, data);
	mlx_hook(data -> mlx_win, 17, 0, exit_game, data);
	mlx_loop_hook(data -> mlx, render_frame, data);
	mlx_loop(data -> mlx);
}

int	mlx_hook(void *win_ptr, int x_event, int x_mask,
                 int (*funct)(), void *param);
// mlx_hook(window pointer, event get, mask get, func when hook, param of func)
// int mlx_hook functions we first pass it our window pointer, then we pass events 
// 		which indicate things like butten press or release and these kind of things
//		in this case we use event 02(keypress) and 03(keyrelease) so the function we gave it
//		will get called once our program sensez a keypress or keyrelease event.
// then we pass it the mask, there is a mask for every event in this case (1L << 0)(for keypress)
// 		and (1L << 1)(for key release)
// then we pass our function and parameter of this function, which get called once it senses of the event we indicated

// mlx_loop_hook makes a function we gave to call itself in every frame
// mlx_loop loops our mlx instance
