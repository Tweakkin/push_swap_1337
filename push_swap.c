/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:20:39 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/23 19:52:29 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_stack *head) {
    t_stack *current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
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