/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:25:14 by atangil           #+#    #+#             */
/*   Updated: 2024/01/15 18:21:54 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include <stdlib.h>

// our main file, it gives the main game function our map after create and validates it.
int	main(int ac, char **av)
{
	if (ac == 2)
		so_long(map_init(av[1]));
	else
		ft_err("Wrong argument number, try again.");
	return (0);
}
