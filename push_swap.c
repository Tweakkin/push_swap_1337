/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:20:39 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/12 22:06:38 by marvin           ###   ########.fr       */
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

int main(int argc, char **argv)
{
	int i;
	int j = 0;
	i = 1;
	t_data *a;
	t_data *b;
	
	if (argc < 2)
		return (0);
	init_data(&a, &b, argv);
	args_to_arr(a, b, argc, argv);
	print_list(a->stack);
	return 0;
}