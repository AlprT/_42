/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:02:32 by atangil           #+#    #+#             */
/*   Updated: 2023/10/23 17:02:32 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Push_swap.h"

int	ft_swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		tmp_data;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (0);
	head = *stack;
	next = head -> next;
	if (!head || !next)
		ft_err();
	tmp_data = next -> data;
	tmp_index = next -> index;
	next -> data = head -> data;
	next -> index = head -> index;
	head -> data = tmp_data;
	head -> index = tmp_index;
	return (1);
}

int	sa(t_stack **stack_a)
{
	if (!ft_swap(stack_a))
		return (0);
	ft_putstr("sa");
	return (1);
}

int	sb(t_stack **stack_b)
{
	if (!ft_swap(stack_b))
		return (0);
	ft_putstr("sb");
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (0);
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr("ss");
	return (1);
}
