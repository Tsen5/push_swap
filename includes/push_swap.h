/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:11:56 by swann             #+#    #+#             */
/*   Updated: 2020/01/15 14:49:54 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_chunk
{
	int				i;
	int				nb;
	int				gap;
}					t_chunk;

/*
** push_swap.c
*/

/*
** moves.c
*/
void	moves(t_stack *a, t_stack *b);

#endif
