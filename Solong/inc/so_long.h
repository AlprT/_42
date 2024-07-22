/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:24:08 by atangil           #+#    #+#             */
/*   Updated: 2024/01/15 18:23:52 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE 64

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*ch;
	void	*wall;
	void	*exit;
	void	*coin;
	void	*ground;
	char	*character;
	char	**map;
	int		map_h;
	int		map_w;
	int		ch_x;
	int		ch_y;
	int		mov;
	int		spd;
	int		mov_num;
	int		coin_num;
}		t_data;

//utils
void	ft_err(char *str);
void	free_map(char **map);

//map initilize
char	**map_init(char *map_path);
int		is_ber(char *map_path);
int		is_rec(char **map);
int		is_logic(char **map);
void	get_coor(char **map, int *w, int *h);

//so_long
void	so_long(char **map);
void	set_sprites(t_data *data);
void	set_player(char	**map, int *x, int *y);
void	put_image(t_data *data);
void	end_game(t_data *data);
int		count_coins(char **map);

//mov
void	move_l(t_data *data, int x, int y);
void	move_r(t_data *data, int x, int y);
void	move_d(t_data *data, int x, int y);
void	move_u(t_data *data, int x, int y);

#endif
