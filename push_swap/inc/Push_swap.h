/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:16:19 by atangil           #+#    #+#             */
/*   Updated: 2023/10/16 18:04:17 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

// structure of the stack
typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

// error
void	ft_err(void);

// free
void	ft_free_stack(t_stack **stack);
void	ft_free(char **str);

// checks
void	ft_check_args(int ac, char **av);
int		ft_check_sorted(t_stack **stack);

// index
void	index_stack(t_stack **stack);

// lst
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *head);
t_stack	*ft_lstnew(int data);
int		ft_lstsize(t_stack *lst);

// print
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

// radix sort
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

// simple sort
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
int		get_min(t_stack **stack, int value);
int		get_distance(t_stack **stack, int index);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

// operators
int		ft_swap(t_stack **stack);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);

int		ft_rotate(t_stack **stack);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);

int		ft_reverserotate(t_stack **stack);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

int		ft_push(t_stack **dest, t_stack **src);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		pa(t_stack **stack_a, t_stack **stack_b);

// libft
long	ft_atoi(const char *str);
void	*ft_bzero(char *str, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *str, int x, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isdigit(int x);

#endif
