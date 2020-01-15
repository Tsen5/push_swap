/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:07:03 by swann             #+#    #+#             */
/*   Updated: 2020/01/13 13:11:27 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tools.h"

void	swap(t_stack *stack)
{
	int		tmp;

	if (stack->size > 1)
	{
		tmp = stack->values[stack->size - 1];
		stack->values[stack->size - 1] = stack->values[stack->size - 2];
		stack->values[stack->size - 2] = tmp;
	}
}

void	double_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}