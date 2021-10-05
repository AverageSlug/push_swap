/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <nlaurids@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:24:54 by nlaurids          #+#    #+#             */
/*   Updated: 2021/03/18 16:24:54 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	while (i < stack->size1 - 1)
	{
		temp = stack->array1[i];
		stack->array1[i] = stack->array1[i + 1];
		stack->array1[i + 1] = temp;
		i++;
	}
}

void	rb(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	while (i < stack->size2 - 1)
	{
		temp = stack->array2[i];
		stack->array2[i] = stack->array2[i + 1];
		stack->array2[i + 1] = temp;
		i++;
	}
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
