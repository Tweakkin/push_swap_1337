/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:20:39 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/10 19:01:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_to_arr(t_data *a, t_data *b, int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		check_for_empty_string(argv[i], a, b, argv);
		a->arr = ft_split(argv[i], ' ');
		if (!a->arr)
			exit_free(a, b, argv);
		j = 0;
		while (a->arr[j] != NULL)
		{
			ft_lstadd_back(&a->stack, ft_lstnew(ft_atoi_safe(a->arr[j])));
			j++;
		}
		free_arr(a->arr);
		a->arr = NULL;
		i++;
	}
}
void    init_data(t_data **a, t_data **b, char **argv)
{
	*a = malloc(sizeof(t_data));
	if (!*a)
		exit_free(*a, *b, argv);
	(*a)->stack = NULL;
	*b = malloc(sizeof(t_data));
	if (!*b)
		exit_free(*a, *b, argv);
	(*b)->stack = NULL;
}

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
    exit(1);
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

void	exit_free(t_data *a, t_data *b, char **args)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (args)
		free_arr(args);
	write(2, "Error\n", 6);
	exit(1);
}

void print_list(t_stack *head) {
    t_stack *current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv)
{
	int i;
	int j = 0;
	i = 1;
	t_data *a;
	t_data *b;

	init_data(&a, &b, argv);
	args_to_arr(a, b, argc, argv);
	print_list(a->stack);
	return 0;
}