/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:57:32 by atangil           #+#    #+#             */
/*   Updated: 2023/10/25 19:03:44 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Push_swap.h"

static int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head -> index;
	max_bits = 0;
	while (head)
	{
		if (head -> index > max)
			max = head -> index;
		head = head -> next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		bit_ctr;
	int		node_ctr;
	int		size;
	int		max_bits;

	bit_ctr = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (bit_ctr < max_bits)
	{
		node_ctr = 0;
		while (node_ctr++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> bit_ctr) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		bit_ctr++;
	}
}
