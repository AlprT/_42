/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:00:02 by atangil           #+#    #+#             */
/*   Updated: 2023/10/23 17:00:02 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Push_swap.h"

int	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;
	t_stack	*head_dest;
	t_stack	*head_src;

	if (ft_lstsize(*src) == 0)
		return (0);
	head_dest = *dest;
	head_src = *src;
	tmp = head_src;
	head_src = head_src -> next;
	*src = head_src;
	if (!head_dest)
	{
		head_dest = tmp;
		head_dest -> next = NULL;
		*dest = head_dest;
	}
	else
	{
		tmp -> next = head_dest;
		*dest = tmp;
	}
	return (1);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_push(stack_a, stack_b))
		return (0);
	ft_putstr("pa");
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_push(stack_b, stack_a))
		return (0);
	ft_putstr("pb");
	return (1);
}
