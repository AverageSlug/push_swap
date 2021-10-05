/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alt_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <nlaurids@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:26:03 by nlaurids          #+#    #+#             */
/*   Updated: 2021/09/28 11:39:04 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_tas(t_stack *stack)
{
	while (1)
	{
		stack->temp = 0;
		if (stack->array1[0] < stack->array1[1]
			&& stack->array1[0] < stack->array1[2])
			stack->temp += 1;
		if (stack->array1[2] > stack->array1[1]
			&& stack->array1[2] > stack->array1[0])
			stack->temp += 2;
		if (stack->temp == 3)
			return ;
		if (stack->temp)
		{
			sa(stack);
			write(1, "sa\n", 3);
		}
		if (stack->temp == 2)
			return ;
		ra(stack);
		write(1, "ra\n", 3);
		if (stack->temp)
			return ;
	}
}

void	ps_chstack(t_stack *stack)
{
	while (stack->temp && stack->size1 > 3)
	{
		if (stack->array1[0] > stack->array1[stack->temp])
			write(1, "ra\n", 3);
		else
			write(1, "pb\n", 3);
		if (stack->array1[0] > stack->array1[stack->temp])
			ra(stack);
		else
			pb(stack);
		stack->temp--;
	}
}

void	ps_smallsort(t_stack *stack)
{
	int	i;
	int	j;

	stack->temp = stack->size1 - 1;
	i = 0;
	j = stack->size1 - 1;
	while (i < j && stack->array1[i] > stack->array1[j])
		i++;
	if (i == j)
	{
		rra(stack);
		write(1, "rra\n", 4);
		pb(stack);
		write(1, "pb\n", 3);
		stack->temp = 0;
	}
	ps_chstack(stack);
	if (stack->size1 > 3)
		ps_smallsort(stack);
	else
	{
		ft_tas(stack);
		stack->temp = 0;
		ps_sort(stack);
	}
}

int	ps_otherargs(t_stack *stack, int n)
{
	if (n == 3 && stack->array1[0] > stack->array1[1])
		write(1, "sa\n", 3);
	if (n == 3 && stack->array1[0] > stack->array1[1])
		sa(stack);
	if (n == 4)
		ft_tas(stack);
	if (n > 4 && n < 34)
		ps_smallsort(stack);
	free(stack->array1);
	free(stack->array2);
	return (0);
}
