/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:20:39 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/14 22:43:55 by yboukhmi         ###   ########.fr       */
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
void    init_data(t_data **a, t_data **b, char **argv)
{
	*a = malloc(sizeof(t_data));
	if (!*a)
		exit_free(*a, *b);
	(*a)->stack = NULL;
	*b = malloc(sizeof(t_data));
	if (!*b)
		exit_free(*a, *b);
	(*b)->stack = NULL;
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

int main(int argc, char **argv)
{
	t_data *a;
	t_data *b;
	
	if (argc < 2)
		return (0);
	init_data(&a, &b, argv);
	args_to_arr(a, b, argc, argv);
	printf("a stack :");
	print_list(a->stack);
	printf("b stack : ");
	print_list(b->stack);
	sa(a);
	print_list(a->stack);
	pa(a, b);
	printf("a stack :");
	print_list(a->stack);
	printf("b stack : ");
	print_list(b->stack);
	pb(, b);
	printf("a stack :");
	print_list(a->stack);
	printf("b stack : ");
	print_list(b->stack);
	ss(a, b);
	printf("a stack :");
	print_list(a->stack);
	printf("b stack : ");
	print_list(b->stack);
	
	free_stack(a);
	free_stack(b);
	return 0;
}