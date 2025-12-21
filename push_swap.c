/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:20:39 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/21 18:18:29 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void print_list(t_stack *head) {
    t_stack *current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int	check_if_sorted(t_stack *a)
{
	t_stack *curr_node;

	if (!a)
		return (1);
	curr_node = a;
	while (curr_node->next != NULL)
	{
		if (curr_node->value > curr_node->next->value)
			return (0);
		curr_node = curr_node->next;
	}
	return (1);
}

int	stack_size(t_stack *a)
{
	int		i;
	t_stack	*curr_node;

	i = 0;
	if (!a)
		return (0);
	curr_node = a;
	while (curr_node != NULL)
	{
		curr_node = curr_node->next;
		i++;
	}
	return (i);
}

void	push_swap(t_data *a, t_data *b)
{
	int	size;

	size = stack_size(a->stack);
	if (check_if_sorted(a->stack) == 1)
		return;
	else if (size == 1)
		return;
	else if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_five(a, b);
	else
		sort_chunks(a, b);
}

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

int main(int argc, char **argv)
{
	t_data *a;
	t_data *b;
	
	if (argc < 2)
		return 0;
	init_data(&a, &b);
	args_to_arr(a, b, argc, argv);
	index_stack(a->stack);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
	return 0;
}