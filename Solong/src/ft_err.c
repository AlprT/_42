/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:39:38 by atangil           #+#    #+#             */
/*   Updated: 2024/01/15 18:32:47 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_err(char *str)
{
	int	i;

	i = 0;
	write(1, "Error\n", 6);
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
	exit(0);
}
