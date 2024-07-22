/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:30:07 by atangil           #+#    #+#             */
/*   Updated: 2023/10/25 18:31:02 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Push_swap.h"

static void	sort_3_sub(t_stack **stack_a)
{
	ra(stack_a);
	sa(stack_a);
	rra(stack_a);
}

static void	sort_3_sub_2(t_stack **stack_a, t_stack *head, int min)
{
	if (head -> next -> index == min)
		sa(stack_a);
	else
		rra(stack_a);
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (ft_check_sorted(stack_a))
		return ;
	if (head -> index == min && head -> next -> index != next_min)
		sort_3_sub(stack_a);
	else if (head -> index == next_min)
		sort_3_sub_2(stack_a, head, min);
	else
	{
		if (head -> next -> index == min)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}
