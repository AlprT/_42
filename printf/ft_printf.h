/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:29:41 by atangil           #+#    #+#             */
/*   Updated: 2023/07/31 15:03:26 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

// main
size_t	ft_printf(const char *str, ...);

// print
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_ptr(unsigned long long ptr);
int		ft_putunsigned(unsigned int i);
int		ft_print_hex(unsigned int n, const char format);
int		ft_putnbr(int i);

// convert
char	*ft_uitoa(unsigned int i);
char	*ft_itoa(int n);

#endif