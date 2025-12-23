/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:39:57 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/24 00:37:14 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_data *a, int print)
{
	if (!a || stack_size(a->stack) < 2)
		return (0);
	swap_nodes(a);
	if (print == 1)
		write(1, "sa\n", 3);
	return (1);
}

int	pa(t_data *a, t_data *b, int print)
{
	t_stack	*temp;

	if (!b || stack_size(b->stack) < 1)
		return (0);
	temp = b->stack;
	b->stack = b->stack->next;
	temp->next = a->stack;
	a->stack = temp;
	if (print == 1)
		write(1, "pa\n", 3);
	return (1);
}

int	ra(t_data *a, int print)
{
	if (!a || stack_size(a->stack) < 2)
		return (0);
	rotate_node(a);
	if (print == 1)
		write(1, "ra\n", 3);
	return (1);
}

int	rra(t_data *a, int print)
{
	if (!a || stack_size(a->stack) < 2)
		return (0);
	reverse_rotate(a);
	if (print == 1)
		write(1, "rra\n", 4);
	return (1);
}
