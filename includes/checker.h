/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:21:25 by swann             #+#    #+#             */
/*   Updated: 2020/01/07 01:57:54 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct		s_stack
{
	int				*values;
	int				size;
}					t_stack;

/*
** mainc.c
*/
int						check_values(int len, char **array);
int						*generate_values(int len, char **array);

/*
** execute.c
*/
int						do_operation(char *line, t_stack *a, t_stack *b);
void					leave_execution(t_stack *a, t_stack *b);
void					execute(t_stack *a, t_stack *b);

/*
** swap.c
*/
void					swap(t_stack *stack);
void					double_swap(t_stack *a, t_stack *b);

/*
** push.c
*/
void					push(t_stack *from, t_stack *to);

/*
** rotate.c
*/
void					rotate(t_stack *stack, int reverse);
void					double_rotate(t_stack *a, t_stack *b, int reverse);

/*
** tools.c
*/
void					remove_from_stack(t_stack *stack, int i);
void					add_to_stack(t_stack *stack, int elem, int index);
void					clean_stack(t_stack *a, t_stack *b);
int						is_valid(t_stack *a, t_stack *b);

#endif
