/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:19:20 by atangil           #+#    #+#             */
/*   Updated: 2023/07/31 15:03:36 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		if (ft_putchar(s[i]) < 0)
			return (-1);
		else
			i++;
	}
	return (i);
}
// null and return checks, prints string and returns its length

int	ft_putnbr(int i)
{
	char	*s;
	int		len;

	if (!i)
		return (ft_putchar('0'));
	s = ft_itoa(i);
	if (!s)
		return (-1);
	len = ft_putstr(s);
	if (len < 0)
	{
		free(s);
		return (-1);
	}
	free(s);
	return (len);
}
// writes a int and returns its length
