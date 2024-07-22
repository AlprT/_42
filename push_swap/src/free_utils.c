/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:51:42 by atangil           #+#    #+#             */
/*   Updated: 2023/10/16 17:13:55 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Push_swap.h"

// frees a string char by char
void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

// frees a stack first all the nodes in it one by one
// then stack itself
void	ft_free_stack(t_stack **stack)
{
	t_stack	*hd;
	t_stack	*tmp;

	hd = *stack;
	while (hd)
	{
		tmp = hd;
		hd = hd -> next;
		free(tmp);
	}
	free(stack);
}
