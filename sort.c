/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:44:14 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/22 16:28:28 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_data *a, t_data *b)
{
	int	min_index;
	int	size;

	size = stack_size(a->stack);
	while (size > 3)
	{
		min_index = find_min_index(a->stack);
		if (min_index <= size / 2)
		{
			while (min_index--)
				ra(a);
		}
		else
		{
			while (min_index++ < size)
				rra(a);
		}
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (b->stack != NULL)
		pa(a, b);
}

void	sort_two(t_data *a)
{
	if (a->stack->value > a->stack->next->value)
		sa(a);
}

void	sort_three(t_data *a)
{
	int	first;
	int	sec;
	int	third;

	first = a->stack->value;
	sec = a->stack->next->value;
	third = a->stack->next->next->value;
	if (first > sec && first > third)
		ra(a);
	else if (sec > first && sec > third)
		rra(a);
	if (a->stack->value > a->stack->next->value)
		sa(a);
}

void	sort_chunks(t_data *a, t_data *b)
{
	int	range;
	int	pushed_count;

	pushed_count = 0;
	range = select_range(stack_size(a->stack));
	while (a->stack != NULL)
	{
		if (a->stack->index < range + pushed_count)
		{
			if (a->stack->index <= pushed_count)
			{
				pb(a , b);
				rb(b);
			}
			else
				pb (a, b);
			pushed_count++;
		}
		else
			ra(a);
	}
	push_back_to_a(a, b);
}

void	push_back_to_a(t_data *a, t_data *b)
{
	int	index_max;
	int position;

	position = 0;
	index_max = stack_size(b->stack) - 1;
	while (b->stack)
	{
		position = position_in_stack(b->stack, index_max);
		move_to_top(b, position, index_max);
		pa(a, b);
		index_max--;
	}
}
