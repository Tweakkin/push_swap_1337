/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:05:54 by marvin            #+#    #+#             */
/*   Updated: 2025/12/12 22:05:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_stack(t_data *data)
{
    t_stack *current;
    t_stack *next;

    if(!data)
        return;
    current = data->stack;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    if (data->arr)
        free_arr(data->arr);
    free(data);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	exit_free(t_data *a, t_data *b)
{
	write(2, "Error\n", 6);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(1);
}