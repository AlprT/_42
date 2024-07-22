/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:02:11 by atangil           #+#    #+#             */
/*   Updated: 2023/10/23 17:02:11 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Push_swap.h"

int	ft_reverserotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;
	t_stack	*next_of_head;

	if (ft_lstsize(*stack) < 2)
		return (0);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		next_of_head = head -> next;
		if (next_of_head -> next == NULL)
		{
			head -> next = NULL;
			break ;
		}
		head = head -> next;
	}
	tail -> next = *stack;
	*stack = tail;
	return (1);
}

int	rra(t_stack **stack_a)
{
	if (!ft_reverserotate(stack_a))
		return (0);
	ft_putstr("rra");
	return (1);
}

int	rrb(t_stack **stack_b)
{
	if (!ft_reverserotate(stack_b))
		return (0);
	ft_putstr("rrb");
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (0);
	ft_reverserotate(stack_a);
	ft_reverserotate(stack_b);
	ft_putstr("rrr");
	return (1);
}
