/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:44:14 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/15 12:57:27 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else if (third > first && third > sec)
		;
	if (a->stack->value > a->stack->next->value)
		sa(a);
	else
		;
}