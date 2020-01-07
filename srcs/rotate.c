/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 00:11:51 by swann             #+#    #+#             */
/*   Updated: 2020/01/07 01:29:30 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rotate(t_stack *stack, int reverse)
{
	int		start;
	int		end;
	int		tmp;

	if (stack->size > 1)
	{
		start = (reverse == 0) ? stack->size - 1 : 0;
		end = (reverse == 0) ? 0 : stack->size - 1;
		tmp = stack->values[start];
		remove_from_stack(stack, start);
		add_to_stack(stack, tmp, end);
	}
}

void	double_rotate(t_stack *a, t_stack *b, int reverse)
{
	rotate(a, reverse);
	rotate(b, reverse);
}