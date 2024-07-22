/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ber.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:56:51 by atangil           #+#    #+#             */
/*   Updated: 2024/01/09 17:53:12 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>

// this function checks if last four chars of the passing argument is ".ber" or not.
int	is_ber(char *map_path)
{
	return (!ft_strncmp(map_path + ft_strlen(map_path) - 4, ".ber", 5));
}
