/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <nlaurids@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:13:21 by nlaurids          #+#    #+#             */
/*   Updated: 2021/09/27 18:45:55 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../includes/struct.h"

int		main(int argc, char **argv);
int		ps_otherargs(t_stack *stack, int n);
int		ft_isnum(char *c);
long	ft_atol(const char *str);
int		ft_strlen(char *str);
int		ft_fwret(char *str, int fd, int ret, t_stack *stack);
void	ft_tas(t_stack *stack);
int		ft_sort_check(t_stack *stack);
void	ps_push(t_stack *stack);
void	ps_sort(t_stack *stack);

#endif