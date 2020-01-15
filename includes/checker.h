/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:21:25 by swann             #+#    #+#             */
/*   Updated: 2020/01/13 13:09:19 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
** checker.c
*/
void					display_result(int result);
int						is_valid(t_stack *a, t_stack *b);

/*
** execute.c
*/
int						do_operation(char *line, t_stack *a, t_stack *b);
void					leave_execution(t_stack *a, t_stack *b);
int						execute(t_stack *a, t_stack *b);

#endif
