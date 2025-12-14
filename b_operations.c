/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:31:31 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/14 22:39:01 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sb(t_data *a)
{
	if (!a || stack_size(a->stack) < 2)
		return (0);
	swap_nodes(a);
	write(1, "sb\n", 3);
	return (1);
}

int	pb(t_data *a, t_data *b)
{
	t_stack *temp;

	if (!a || stack_size(a->stack) < 1)
		return (0);
	temp = a->stack;
	a->stack = a->stack->next;
	temp->next = b->stack;
	b->stack = temp;
	write(1, "pb\n", 3);
	return (1);
}