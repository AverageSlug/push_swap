/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:46:14 by marvin            #+#    #+#             */
/*   Updated: 2021/03/16 17:46:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_fwret(char *str, int fd, int ret, t_stack *stack)
{
	if (stack->array1)
		free(stack->array1);
	if (stack->array2)
		free(stack->array2);
	write(fd, str, ft_strlen(str));
	return (ret);
}

int	ft_isnum(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-')
		i++;
	i--;
	while (c[++i])
		if (!(c[i] >= '0' && c[i] <= '9'))
			return (0);
	return (1);
}

long	ft_atol(const char *str)
{
	unsigned long long	p;
	long				b;

	p = 0;
	b = 1;
	if (*str == '-')
	{
		if (*str++ == '-')
			b = -1;
	}
	while (*str >= 48 && *str <= 57)
	{
		if (p > 9223372036854775807)
			return ((b - 1) / 2);
		p = p * 10 + (*str++ - 48);
	}
	return ((long)p * b);
}
