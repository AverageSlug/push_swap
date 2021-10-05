/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <nlaurids@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:32:18 by nlaurids          #+#    #+#             */
/*   Updated: 2021/03/18 16:32:18 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack *stack)
{
	int	i;
	int	temp;

	i = stack->size1 - 1;
	while (i > 0)
	{
		temp = stack->array1[i];
		stack->array1[i] = stack->array1[i - 1];
		stack->array1[i - 1] = temp;
		i--;
	}
}

void	rrb(t_stack *stack)
{
	int	i;
	int	temp;

	i = stack->size2 - 1;
	while (i > 0)
	{
		temp = stack->array2[i];
		stack->array2[i] = stack->array2[i - 1];
		stack->array2[i - 1] = temp;
		i--;
	}
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
