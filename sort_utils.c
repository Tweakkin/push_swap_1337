/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:26:03 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/23 17:23:55 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *s)
{
	t_stack	*ptr;
	t_stack *curr;

	ptr = s;
	while (ptr)
	{
		ptr->index = 0;
		curr = s;
		while (curr)
		{
			if (ptr->value > curr->value)
				ptr->index++;
			curr = curr->next;
		}
		ptr = ptr->next;
	}
}

int	position_in_stack(t_stack *s, int index)
{
	int pos;

	pos = 0;
	while (s)
	{
		if (index == s->index)
			return (pos);
		pos++;
		s = s->next;
	}
	return (-1);
}

int	select_range(int size_of_stack)
{
	int	range;

	range = 0;
	if (size_of_stack <= 100)
		range = 15;
	else
		range = 30;
	return (range);
}

int	find_min_index(t_stack *s)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	min = s->value;
	index = i;
	while (s)
	{
		if (s->value < min)
		{
			index = i;
			min = s->value; 
		}
		s = s->next;
		i++;
	}
	return (index);
}

void	move_to_top(t_data *b, int position, int index_max)
{
	if (position <= (index_max / 2))
	{
		while (position > 0)
		{
			rb(b, 1);
			position--;
		}
	}
	else
	{
		while (position <= index_max)
		{
			rrb(b, 1);
			position++;
		}
	}
}