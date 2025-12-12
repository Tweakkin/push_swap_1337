/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:09:07 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/12/12 21:42:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi_safe(const char *str, t_data *a, t_data *b)
{
	size_t	i;
	int		sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		result = (result * 10) + (str[i] - '0');
		if (sign == 1 && (sign * result) > INT_MAX)
			exit_free(a, b);
		else if (sign == -1 && (sign * result) < INT_MIN)
			exit_free(a, b);
		i++;
	}
	return ((int)result * sign);
}
