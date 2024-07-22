/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:17:34 by atangil           #+#    #+#             */
/*   Updated: 2023/10/25 18:36:53 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Push_swap.h"

int	get_min(t_stack **stack, int value)
{
	t_stack	*head;
	int		min;

	head = *stack;
	min = head -> index;
	while (head -> next)
	{
		head = head -> next;
		if ((head -> index < min) && head -> index != value)
			min = head -> index;
	}
	return (min);
}

int	get_distance(t_stack **stack, int index)
{
	t_stack	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head -> index == index)
			break ;
		distance++;
		head = head -> next;
	}
	return (distance);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (ft_check_sorted(stack_a) || !ft_lstsize(*stack_a)
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
