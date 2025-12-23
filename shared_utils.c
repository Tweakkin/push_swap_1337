/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_utlis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:51:36 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/23 19:52:35 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_data(t_data **a, t_data **b)
{
	*a = malloc(sizeof(t_data));
	if (!*a)
		exit_free(*a, *b);
	(*a)->stack = NULL;
	(*a)->arr = NULL;
	*b = malloc(sizeof(t_data));
	if (!*b)
		exit_free(*a, *b);
	(*b)->stack = NULL;
	(*b)->arr = NULL;
}

void	args_to_arr(t_data *a, t_data *b, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		check_for_empty_string(argv[i], a, b);
		check_for_invalid_char(argv[i], a, b);
		a->arr = ft_split(argv[i], ' ');
		if (!a->arr)
			exit_free(a, b);
		j = 0;
		while (a->arr[j] != NULL)
		{
			check_for_duplicate(ft_atoi_safe(a->arr[j], a, b), a, b);
			ft_lstadd_back(&a->stack, ft_lstnew(ft_atoi_safe(a->arr[j], a, b)));
			j++;
		}
		free_arr(a->arr);
		a->arr = NULL;
		i++;
	}
}