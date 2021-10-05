/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <nlaurids@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:13:10 by nlaurids          #+#    #+#             */
/*   Updated: 2021/09/17 17:13:10 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_pivot_find(t_stack *stack, int l)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	while (j < stack->size1)
	{
		i = 0;
		k = 0;
		while (i < stack->size1)
		{
			if (stack->array1[j] > stack->array1[i])
				k++;
			i++;
		}
		if (k == ((l + 1) * (stack->size1 - stack->size1 % stack->temp))
			/ stack->temp)
			break ;
		j++;
	}
	stack->pivots[l] = stack->array1[j];
}

void	ps_pivot_fill(t_stack *stack)
{
	int	l;

	l = 1;
	while (l < stack->temp - 1)
	{
		stack->pivots[l] = 0;
		ps_pivot_find(stack, l);
		l++;
	}
	ps_push(stack);
	ps_sort(stack);
}

int	ps_parse(t_stack *stack, int n, char **list)
{
	int	i;
	int	j;

	stack->size1 = n - 1;
	stack->size2 = 0;
	i = 0;
	while (i < stack->size1)
	{
		if (!ft_isnum(list[i + 1]) || ft_atol(list[i + 1]) < -2147483648
			|| ft_atol(list[i + 1]) > 2147483647)
			return (1);
		stack->array1[i] = ft_atol(list[i + 1]);
		stack->array2[i] = 0;
		i++;
	}
	i = 0;
	while (i < stack->size1)
	{
		j = -1;
		while (++j < stack->size1)
			if (stack->array1[i] == stack->array1[j] && i != j)
				return (1);
		i++;
	}
	return (0);
}

void	ps_pivot_calc(t_stack *stack)
{
	int	i;
	int	j;

	stack->temp = 1;
	while (1)
	{
		i = 2 * stack->temp * stack->temp;
		if (i >= stack->size1)
			break ;
		stack->temp++;
	}
	j = 2 * (stack->temp - 1) * (stack->temp - 1);
	if ((stack->size1 - j) + (stack->size1 - i) < 0)
		stack->temp--;
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (0);
	stack.array1 = malloc(sizeof(int) * (argc - 1));
	if (!stack.array1)
		return (ft_fwret("Error\n", 1, -1, &stack));
	stack.array2 = malloc(sizeof(int) * (argc - 1));
	if (!stack.array2)
		return (ft_fwret("Error\n", 1, -1, &stack));
	if (ps_parse(&stack, argc, argv))
		return (ft_fwret("Error\n", 1, -1, &stack));
	if (ft_sort_check(&stack))
		return (ft_fwret("", 1, 0, &stack));
	if (argc < 34)
		return (ps_otherargs(&stack, argc));
	ps_pivot_calc(&stack);
	stack.pivots = malloc(sizeof(int) * stack.temp);
	if (!stack.pivots)
		return (ft_fwret("Error\n", 1, -1, &stack));
	ps_pivot_fill(&stack);
	free(stack.pivots);
	return (ft_fwret("", 1, 0, &stack));
}
