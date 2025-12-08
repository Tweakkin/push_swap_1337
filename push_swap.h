/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:20:36 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/08 16:53:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
}t_stack;

typedef struct s_data
{
    t_stack *stack;
    char **arr;
}t_data;

char	**ft_split(char const *s, char c);
void	exit_free(t_data *a, t_data *b, char **args);
void	free_arr(char **arr);
void    free_stack(t_data *data);
void    init_data(t_data **a, t_data **b, char **argv);
int	ft_strlen(const char *str);
void	check_for_empty_string(char *arg, t_data *a, t_data *b, char **argv);

#endif