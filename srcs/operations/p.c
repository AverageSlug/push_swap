/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <nlaurids@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:35:21 by nlaurids          #+#    #+#             */
/*   Updated: 2021/03/18 16:35:21 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(t_stack *stack)
{
	int	temp;
	int	i;

	temp = stack->array1[0];
	i = 0;
	while (i < stack->size1 - 1)
	{
		stack->array1[i] = stack->array1[i + 1];
		i++;
	}
	stack->array1[i] = 0;
	i = stack->size2;
	while (i > 0)
	{
		stack->array2[i] = stack->array2[i - 1];
		i--;
	}
	stack->array2[i] = temp;
	stack->size1--;
	stack->size2++;
}

void	pa(t_stack *stack)
{
	int	temp;
	int	i;

	temp = stack->array2[0];
	i = 0;
	while (i < stack->size2 - 1)
	{
		stack->array2[i] = stack->array2[i + 1];
		i++;
	}
	stack->array2[i] = 0;
	i = stack->size1;
	while (i > 0)
	{
		stack->array1[i] = stack->array1[i - 1];
		i--;
	}
	stack->array1[i] = temp;
	stack->size1++;
	stack->size2--;
}
