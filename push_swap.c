/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:20:39 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/06 15:44:34 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_data(t_data **a, t_data **b, char **argv)
{
    *a = malloc(sizeof(t_data));
    if (!*a)
        exit_free();
    (*a)->stack = NULL;
    *b = malloc(sizeof(t_data));
    if (!*b)
        exit_free();
    (*b)->stack = NULL;
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