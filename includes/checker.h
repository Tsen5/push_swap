/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:21:25 by swann             #+#    #+#             */
/*   Updated: 2020/01/17 16:34:50 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
** checker.c
*/
void					display_result(int result);

/*
** execute.c
*/
int						do_operation(char *line, t_stack *a, t_stack *b);
void					leave_execution(t_stack *a, t_stack *b);
int						execute(t_stack *a, t_stack *b);

#endif
