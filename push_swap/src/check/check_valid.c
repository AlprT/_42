/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:26:12 by atangil           #+#    #+#             */
/*   Updated: 2023/10/16 17:16:18 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Push_swap.h"

// checks if any of the members of "av" array contains
// value "num", i is just a counter from parent
static int	ft_contains(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

// checks the string value if its numeric or not
static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (i);
}

// checks the args if they're valid or not
void	ft_check_args(int ac, char **av)
{
	long	tmp;
	char	**args;
	int		i;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		args = av;
		i = 1;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || ft_contains(tmp, args, i)
			|| !(tmp > -2147483648 && tmp < 2147483647))
			ft_err();
		i++;
	}
	if (ac == 2)
		ft_free(args);
}

int	ft_check_sorted(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next_of_head;

	head = *stack;
	while (head && head -> next)
	{
		next_of_head = head -> next;
		if (head -> data > next_of_head -> data)
			return (0);
		head = head -> next;
	}
	return (1);
}
