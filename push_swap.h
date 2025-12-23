/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:20:36 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/23 20:22:02 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>

typedef struct s_stack
{
    int value;
    int index;
    struct s_stack *next;
}t_stack;

typedef struct s_data
{
    t_stack *stack;
    char **arr;
}t_data;

char	**ft_split(char const *s, char c);
void	exit_free(t_data *a, t_data *b);
void	free_arr(char **arr);
void    free_stack(t_data *data);
void    init_data(t_data **a, t_data **b);
int	ft_strlen(const char *str);
void	check_for_empty_string(char *arg, t_data *a, t_data *b);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
int	ft_atoi_safe(const char *str, t_data *a, t_data *b);
void	check_for_invalid_char(char *agr, t_data *a, t_data *b);
void	check_for_duplicate(int num, t_data *a, t_data *b);
int	stack_size(t_stack *a);
int	check_if_sorted(t_stack *a);
int	sa(t_data *a, int print);
int	sb(t_data *b, int print);
void    swap_nodes(t_data *s);
int ss(t_data *a, t_data *b, int print);
int	pa(t_data *a, t_data *b, int print);
int	pb(t_data *a, t_data *b, int print);
t_stack	*ft_lstlast(t_stack *lst);
void	rotate_node(t_data *s);
int ra(t_data *a, int print);
int	rr(t_data *a, t_data *b, int print);
int rb(t_data *b, int print);
void reverse_rotate(t_data *s);
int	rra(t_data *a, int print);
int	rrb(t_data *b, int print);
int	rrr(t_data *a, t_data *b, int print);
void	sort_three(t_data *a);
void	sort_two(t_data *a);
int	find_min_index(t_stack *s);
void	sort_five(t_data *a, t_data *b);
void	push_swap(t_data *a, t_data *b);
void	index_stack(t_stack *s);
void	sort_chunks(t_data *a, t_data *b);
int	position_in_stack(t_stack *s, int index);
void	push_back_to_a(t_data *a, t_data *b);
int	select_range(int size_of_stack);
void	move_to_top(t_data *b, int position, int index_max);
void	args_to_arr(t_data *a, t_data *b, int argc, char **argv);

#endif