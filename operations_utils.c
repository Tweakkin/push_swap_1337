/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:29:38 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/22 16:30:10 by yboukhmi         ###   ########.fr       */
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

void	rotate_node(t_data *s)
{
	t_stack *last_node;
	t_stack *first_node;

	last_node = ft_lstlast(s->stack);
	first_node = s->stack;
	s->stack = first_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
}

void reverse_rotate(t_data *s)
{
	t_stack *last_node;
	t_stack *sec_last_node;

	last_node = ft_lstlast(s->stack);
	sec_last_node = s->stack;
	while (sec_last_node->next->next != NULL)
		sec_last_node = sec_last_node->next;
	last_node->next = s->stack;
	s->stack = last_node;
	sec_last_node->next = NULL;
}