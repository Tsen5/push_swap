/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 00:11:23 by swann             #+#    #+#             */
/*   Updated: 2020/01/07 01:04:28 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	push(t_stack *from, t_stack *to)
{
	if (from->size > 0)
	{
		add_to_stack(to, from->values[from->size - 1], to->size);
		remove_from_stack(from, (from->size - 1));
	}
}