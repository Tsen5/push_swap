/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:11:56 by swann             #+#    #+#             */
/*   Updated: 2020/01/15 18:11:52 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_chunk
{
	int				i;
	int				nb;
	int				gap;
	int				min;
	int				max;
}					t_chunk;

/*
** push_swap.c
*/

/*
** moves.c
*/
void	moves(t_stack *a, t_stack *b);

#endif
