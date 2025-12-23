/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:20:09 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/23 20:21:10 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int handle_operations(t_data *a, t_data *b, char *move)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		pb(a, b, 0);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

void	checking(t_data *a, t_data *b)
{
	if (check_if_sorted(a->stack) == 1 && b->stack == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int main(int argc, char **argv)
{
	t_data *a;
	t_data *b;
	char *line;
	
	if (argc < 2)
		return 0;
	init_data(&a, &b);
	args_to_arr(a, b, argc, argv);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		if (handle_operations(a, b, line) == 0)
		{
			write(2, "Error\n", 6);
			free_stack(a);
			free_stack(b);
			exit(1);
		}
		free(line);
	}
	checking(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}