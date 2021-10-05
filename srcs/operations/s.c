/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <nlaurids@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:19:23 by nlaurids          #+#    #+#             */
/*   Updated: 2021/03/18 16:19:23 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack *stack)
{
	int	temp;

	if (stack->size1 > 2)
	{
		temp = stack->array1[0];
		stack->array1[0] = stack->array1[1];
		stack->array1[1] = temp;
	}
}

void	sb(t_stack *stack)
{
	int	temp;

	if (stack->size2 > 2)
	{
		temp = stack->array2[0];
		stack->array2[0] = stack->array2[1];
		stack->array2[1] = temp;
	}
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
