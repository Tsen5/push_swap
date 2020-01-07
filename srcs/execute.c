/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:34:53 by swann             #+#    #+#             */
/*   Updated: 2020/01/07 01:58:50 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		do_operation(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(a);
	else if (ft_strcmp(line, "sb") == 0)
		swap(b);
	else if (ft_strcmp(line, "ss") == 0)
		double_swap(a, b);
	else if (ft_strcmp(line, "pa") == 0)
		push(b, a);
	else if (ft_strcmp(line, "pb") == 0)
		push(a, b);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		double_rotate(a, b, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rotate(a, 1);
	else if (ft_strcmp(line, "rrb") == 0)
		rotate(b, 1);
	else if (ft_strcmp(line, "rrr") == 0)
		double_rotate(a, b, 1);
	else
		return (0);
	return (1);
}

// static void		print_stack(t_stack *stack)
// {
// 	int		i;

// 	i = 0;
// 	ft_putstr("STACK : ");
// 	while (i < stack->size)
// 	{
// 		ft_putnbr(stack->values[i]);
// 		ft_putchar(' ');
// 		i++;
// 	}
// 	ft_putchar('\n');
// }

void	leave_execution(t_stack *a, t_stack *b)
{
	ft_putendl_col_fd("OK", GRN, 2);
	clean_stack(a, b);
}

void	execute(t_stack *a, t_stack *b)
{
	char	*line;

	if (is_valid(a, b) == 1)
		return (leave_execution(a, b));
	while (42)
	{
		ft_putstr("checker_$> ");
		get_next_line(0, &line);
		line = ft_strtrimf(line);
		if (do_operation(line, a, b) == 1)
		{
			free(line);
			// print_stack(a);
			// print_stack(b);
			if (is_valid(a, b) == 1)
			{
				ft_putendl_col_fd("OK", GRN, 2);
				break ;
			}
		}
		else
		{
			free(line);
			ft_putendl_col_fd("KO", YEL, 2);
			break ;
		}
	}
}