/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:09:24 by atangil           #+#    #+#             */
/*   Updated: 2023/07/31 14:59:23 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hcount(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}
// counts length of a hexadecimal value

static int	ft_put_hex(unsigned int n, const char format, int temp)
{
	if (n >= 16)
	{
		temp = ft_put_hex(n / 16, format, temp);
		if (temp < 0)
			return (-1);
		temp = ft_put_hex(n % 16, format, temp);
		if (temp < 0)
			return (-1);
	}
	else
	{
		if (n > 9)
		{
			if (format == 'x')
				if (ft_putchar(n - 10 + 'a') < 0)
					return (-1);
			if (format == 'X')
				if (ft_putchar(n - 10 + 'A') < 0)
					return (-1);
		}
		else
			return (ft_putchar(n + 48));
	}
	return (1);
}
// prints hexadecimal value

int	ft_print_hex(unsigned int n, const char format)
{
	int	temp;

	temp = 0;
	if (n == 0)
	{
		return (ft_putchar('0'));
	}
	else
		if (ft_put_hex(n, format, temp) < 0)
			return (-1);
	return (ft_hcount(n));
}
// main hex func
