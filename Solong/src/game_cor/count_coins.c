/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_coins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:22:02 by atangil           #+#    #+#             */
/*   Updated: 2024/01/10 17:23:48 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// basicly counts all of the coins

int	count_coins(char **map)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}
