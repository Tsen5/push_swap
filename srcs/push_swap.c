/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:14:05 by swann             #+#    #+#             */
/*   Updated: 2020/01/15 16:56:53 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tools.h"
#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		if (check_values(argc, argv) == 1)
		{
			a.size = argc - 1;
			if ((a.values = generate_values(argc, argv)) != NULL)
			{
				b.size = 0;
				b.values = NULL;
				moves(&a, &b);
				clean_stack(&a, &b);
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
