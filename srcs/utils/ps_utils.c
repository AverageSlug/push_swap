/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <nlaurids@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:03:50 by nlaurids          #+#    #+#             */
/*   Updated: 2021/09/27 18:59:38 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_sort_check(t_stack *stack)
{
	int	i;

	i = 0;
	while (++i < stack->size1)
		if (stack->array1[i - 1] > stack->array1[i])
			return (0);
	return (1);
}

void	ps_rotate(t_stack *stack, int i)
{
	while (i)
	{
		if (stack->size2 - i > i)
		{
			rb(stack);
			write(1, "rb\n", 3);
			i--;
		}
		else
		{
			rrb(stack);
			write(1, "rrb\n", 4);
			if (++i > stack->size2 - 1)
				break ;
		}
	}
}

void	ps_lowargs(t_stack *stack)
{
	while (stack->temp && stack->array2[0] < stack->array1[stack->size1 - 1])
	{
		rra(stack);
		write(1, "rra\n", 4);
		stack->temp--;
	}
	while (stack->array2[0] > stack->array1[0])
	{
		ra(stack);
		write(1, "ra\n", 3);
		stack->temp++;
	}
}

void	ps_sort(t_stack *stack)
{
	int	i[3];

	while (stack->size2 > 0)
	{
		i[2] = 0;
		i[0] = stack->array2[0];
		i[1] = 0;
		while (++i[2] < stack->size2)
		{
			if (stack->array2[i[2]] > i[0])
				i[1] = i[2];
			if (stack->array2[i[2]] > i[0])
				i[0] = stack->array2[i[2]];
		}
		ps_rotate(stack, i[1]);
		if (stack->size1 + stack->size2 < 33)
			ps_lowargs(stack);
		pa(stack);
		write(1, "pa\n", 3);
	}
	while (stack->size1 + stack->size2 < 33 && !ft_sort_check(stack))
	{
		rra(stack);
		write(1, "rra\n", 4);
	}
}

void	ps_push(t_stack *stack)
{
	int	i[2];

	i[0] = 1;
	while (i[0] < stack->temp - 1)
	{
		i[1] = 0;
		while (i[1] < stack->size1)
		{
			if (stack->array1[0] < stack->pivots[i[0]])
				write(1, "pb\n", 3);
			else
				write(1, "ra\n", 3);
			if (stack->array1[0] < stack->pivots[i[0]])
				pb(stack);
			else
				ra(stack);
			i[1]++;
		}
		i[0]++;
	}
	while (stack->size1 > 0)
	{
		pb(stack);
		write(1, "pb\n", 3);
	}
}
