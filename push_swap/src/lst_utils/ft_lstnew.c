/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:05:30 by atangil           #+#    #+#             */
/*   Updated: 2023/10/23 17:05:30 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Push_swap.h"

t_stack	*ft_lstnew(int data)
{
	t_stack	*nw;

	nw = (t_stack *)malloc(sizeof(t_stack));
	if (!nw)
		return (0);
	nw -> next = NULL;
	nw -> index = -1;
	nw -> data = data;
	return (nw);
}
