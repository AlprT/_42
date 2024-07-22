/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:38:45 by atangil           #+#    #+#             */
/*   Updated: 2023/07/31 14:58:03 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static size_t	ft_format(va_list args, const char form)
{
	size_t	len;

	len = 0;
	if (form == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (form == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (form == 'd' || form == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (form == '%')
		len = ft_putchar('%');
	else if (form == 'u')
		len = ft_putunsigned(va_arg(args, unsigned int));
	else if (form == 'x' || form == 'X')
		len = ft_print_hex(va_arg(args, unsigned int), form);
	else if (form == 'p')
		len = ft_ptr(va_arg(args, unsigned long long));
	return (len);
}

static int	ft_check(const char *str, va_list args, int i)
{
	int	temp;

	temp = 0;
	if (str[i] == '%')
	{
		temp = ft_format(args, str[i + 1]);
		if (temp < 0)
			return (-1);
		else
			return (temp);
	}
	else
	{
		if (ft_putchar(str[i]) < 0)
			return (-1);
		else 
			return (1);
	}
}

size_t	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		temp;

	temp = 0;
	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		temp = ft_check(str, args, i);
		if (str[i] == '%')
			i++;
		if (temp < 0)
			return (-1);
		else
		{
			len += temp;
		}
		i++;
	}
	va_end(args);
	return (len);
}
