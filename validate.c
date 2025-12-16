/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:53:55 by marvin            #+#    #+#             */
/*   Updated: 2025/12/16 23:36:06 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_empty_string(char *arg, t_data *a, t_data *b)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) == 0)
		exit_free(a, b);
	else if (ft_strlen(arg) > 0)
	{
		while (arg[i])
		{
			if (arg[i] != ' ')
				return ;
			i++;
		}
	}
	exit_free(a, b);
}

void	check_for_duplicate(int num, t_data *a, t_data *b)
{
	t_stack *curr_node;
	
	curr_node = a->stack;
	while (curr_node != NULL)
	{
		if (num == curr_node->value)
			exit_free(a, b);
		curr_node = curr_node->next;
	}
	return;
}

void	check_for_invalid_char(char *agr, t_data *a, t_data *b)
{
	int	i;

	i = 0;
	while(agr[i])
	{
		if ((agr[i] <= '9' && agr[i] >= '0') || agr[i] == ' ')
			;
		else if (agr[i] == '-' || agr[i] == '+')
		{
			if (!(i == 0 || agr[i-1] == ' ') || !(agr[i+1] >= '0' && agr[i+1] <= '9'))
				exit_free(a, b);
		}
		else
			exit_free(a, b);
		i++;
	}
	return ;
}