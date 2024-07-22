/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:35:17 by atangil           #+#    #+#             */
/*   Updated: 2023/10/16 17:48:45 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Push_swap.h"
#include <stdlib.h>
#include <unistd.h>

// prints error and exits
void	ft_err(void)
{
	write(2, "Error!\n", 7);
	exit (0);
}
