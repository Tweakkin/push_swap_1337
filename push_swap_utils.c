/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:09:07 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/14 23:43:08 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi_safe(const char *str, t_data *a, t_data *b)
{
	size_t	i;
	int		sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		result = (result * 10) + (str[i] - '0');
		if (sign == 1 && (sign * result) > INT_MAX)
			exit_free(a, b);
		else if (sign == -1 && (sign * result) < INT_MIN)
			exit_free(a, b);
		i++;
	}
	return ((int)result * sign);
}

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
