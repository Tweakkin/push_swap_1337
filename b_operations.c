/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:31:31 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/23 17:22:53 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sb(t_data *b, int print)
{
	if (!b || stack_size(b->stack) < 2)
		return (0);
	swap_nodes(b);
	if (print == 1)
		write(1, "sb\n", 3);
	return (1);
}

int	pb(t_data *a, t_data *b, int print)
{
	t_stack *temp;

	if (!a || stack_size(a->stack) < 1)
		return (0);
	temp = a->stack;
	a->stack = a->stack->next;
	temp->next = b->stack;
	b->stack = temp;
	if (print == 1)
		write(1, "pb\n", 3);
	return (1);
}

int rb(t_data *b, int print)
{
	if (!b || stack_size(b->stack) < 2)
		return (0);
	rotate_node(b);
	if (print == 1)
		write(1, "rb\n", 3);
	return (1);
}

int	rrb(t_data *b, int print)
{
	if (!b || stack_size(b->stack) < 2)
		return (0);
	reverse_rotate(b);
	if (print == 1)
		write(1, "rrb\n", 4);
	return (1);
}