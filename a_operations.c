/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:39:57 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/14 22:44:48 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_data *a)
{
	if (!a || stack_size(a->stack) < 2)
		return (0);
	swap_nodes(a);
	write(1, "sa\n", 3);
	return (1);
}

int	pa(t_data *a, t_data *b)
{
	t_stack *temp;

	if (!b || stack_size(b->stack) < 1)
		return (0);
	temp = b->stack;
	b->stack = b->stack->next;
	temp->next = a->stack;
	a->stack = temp;
	write(1, "pa\n", 3);
	return (1);
}