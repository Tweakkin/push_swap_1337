/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:20:09 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/23 16:52:22 by yboukhmi         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_data *a;
	t_data *b;
	
	if (argc < 2)
		return 0;
	init_data(&a, &b);
	args_to_arr(a, b, argc, argv);
	index_stack(a->stack);
	print_list(a->stack);
	while (1)
	{
		
	}
	return (0);
}