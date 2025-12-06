/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:20:36 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/06 12:40:30 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
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

#endif