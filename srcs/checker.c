/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:15:23 by swann             #+#    #+#             */
/*   Updated: 2020/01/13 13:12:06 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tools.h"
#include "../includes/checker.h"

void	display_result(int result)
{
	if (result == 1)
		ft_putendl_col_fd("OK", GRN, 1);
	else if (result == 0)
		ft_putendl_col_fd("KO", YEL, 2);
	else
		ft_putendl_col_fd("Error : bad instruction", RED, 2);
}

int		is_valid(t_stack *a, t_stack *b)
{
	int		i;

	if (b->size > 0)
		return (0);
	if (a->size == 1)
		return (1);
	i = 1;
	while (i < a->size)
	{
		if (a->values[i] > a->values[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		result;

	if (argc > 1)
	{
		if (check_values(argc, argv) == 1)
		{
			a.size = argc - 1;
			if ((a.values = generate_values(argc, argv)) != NULL)
			{
				b.size = 0;
				b.values = NULL;
				result = execute(&a, &b);
				display_result(result);
			}
			else
				ft_putendl_col_fd("Error : values must be different", RED, 2);
		}
		else
			ft_putendl_col_fd("Error : values are incorrect", RED, 2);
	}
	else
		ft_putendl_col_fd("Error : not enough argument", RED, 2);
	return (0);
}
