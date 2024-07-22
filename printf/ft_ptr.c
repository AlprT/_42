/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:46:03 by atangil           #+#    #+#             */
/*   Updated: 2023/07/31 11:47:43 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned long long a)
{
	int	len;

	len = 0;
	while (a != 0)
	{
		a /= 16;
		len++;
	}
	return (len);
}

static void	ft_put_hexx(unsigned long long n)
{
	if (n >= 16)
	{
		ft_put_hexx(n / 16);
		ft_put_hexx(n % 16);
	}
	else
	{
		if (n > 9)
			ft_putchar(n - 10 + 'a');
		else
			ft_putchar(n + 48);
	}
}

int	ft_ptr(unsigned long long n)
{
	int	len;
	int	temp;

	len = 0;
	temp = ft_putstr("0x");
	if (temp < 0)
		return (-1);
	else
		len += temp;
	if (n == 0)
	{
		if (ft_putchar('0') < 0)
			return (-1);
		len++;
	}
	else
		ft_put_hexx(n);
	return (hex_len(n) + len);
}
