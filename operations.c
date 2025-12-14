/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:35:23 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/14 22:01:18 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nodes(t_data *s)
{
	t_stack *first;
	t_stack *second;

	first = s->stack;
	second = s->stack->next;

	first->next = second->next;
	second->next = first;
	s->stack = second;
}

int ss(t_data *a, t_data *b)
{
	int	swapped;

	swapped = 0;
	if (a && stack_size(a->stack) >= 2)
	{	
		swap_nodes(a);
		swapped = 1;
	}
	if (b && stack_size(b->stack) >= 2)
	{	
		swap_nodes(b);
		swapped = 1;
	}
	if (swapped == 1)
		return (write(1, "ss\n", 3), 1);
	return (0);
}