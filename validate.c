/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:53:55 by marvin            #+#    #+#             */
/*   Updated: 2025/12/08 16:53:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_empty_string(char *arg, t_data *a, t_data *b, char **argv)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) == 0)
    {
        printf("Empty exit\n");
		exit_free(a, b, argv);
    }
	else if (ft_strlen(arg) > 0)
	{
		while (arg[i])
		{
			if (arg[i] != ' ')
				return ;
			i++;
		}
	}
    printf("Empty exit\n");
	exit_free(a, b, argv);
}