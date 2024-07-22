/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:02:06 by atangil           #+#    #+#             */
/*   Updated: 2023/10/23 17:02:06 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Push_swap.h"

int	ft_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_lstsize(*stack) < 2)
		return (0);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head -> next;
	head -> next = NULL;
	tail -> next = head;
	return (1);
}

int	ra(t_stack **stack_a)
{
	if (!ft_rotate(stack_a))
		return (0);
	ft_putstr("ra");
	return (1);
}

int	rb(t_stack **stack_b)
{
	if (!ft_rotate(stack_b))
		return (0);
	ft_putstr("rb");
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (0);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr("rr");
	return (1);
}
