/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:35:23 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/23 17:29:21 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ss(t_data *a, t_data *b, int print)
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
	{
		if (print == 1)
			write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}

int	rr(t_data *a, t_data *b, int print)
{
	int	rotated;

	rotated = 0;
	if (a && stack_size(a->stack) >= 2)
	{
		rotate_node(a);
		rotated = 1;
	}
	if (b && stack_size(b->stack) >= 2)
	{
		rotate_node(b);
		rotated = 1;
	}
	if (rotated == 1)
	{
		if (print == 1)
			write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}

int	rrr(t_data *a, t_data *b, int print)
{
	int	rotated;

	rotated = 0;
	if (a && stack_size(a->stack) >= 2)
	{
		reverse_rotate(a);
		rotated = 1;
	}
	if (b && stack_size(b->stack) >= 2)
	{
		reverse_rotate(b);
		rotated = 1;
	}
	if (rotated == 1)
	{
		if (print == 1)
			write(1, "rrr\n", 4);
		return (1);
	}
	return (0);
}