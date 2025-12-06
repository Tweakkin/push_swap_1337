/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:20:39 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/06 18:03:51 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_data(t_data **a, t_data **b, char **argv)
{
	*a = malloc(sizeof(t_data));
	if (!*a)
		exit_free(*a, *b, &argv);
	(*a)->stack = NULL;
	*b = malloc(sizeof(t_data));
	if (!*b)
		exit_free(*a, *b, &argv);
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

int main(int argc, char **argv)
{
	int i;
	int j = 0;
	i = 1;
	t_data *a;
	t_data *b;

	a = malloc(sizeof(t_data));
	if (!a)
		printf("error mallocing a");
	b = malloc(sizeof(t_data));
	if (!b)
		printf("error mallocing b");
	while (i < argc)
	{
		a->arr = ft_split(argv[i], ' ');
		j = 0;
		while (a->arr[j])
			printf("%s\n", a->arr[j++]);
		i++;
	}
	return 0;
}