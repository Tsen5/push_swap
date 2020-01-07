/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:15:23 by swann             #+#    #+#             */
/*   Updated: 2020/01/07 02:24:22 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		check_values(int len, char **array)
{
	int		i;
	char	*tmp;
	int		check;

	i = 1;
	while (i < len)
	{
		tmp = ft_strtrim(array[i]);
		if (ft_isnumber(tmp) == 0)
			check = 0;
		else
			check = (atol(tmp) > INT_MAX || atol(tmp) < INT_MIN) ? 0 : 1;
		free(tmp);
		if (check == 0)
			return (0);
		i++;
	}
	return (1);
}

int		*generate_values(int len, char **array)
{
	int		*values;
	int		i;
	int		j;

	if (!(values = (int *)malloc(sizeof(int) * (len - 1))))
		return (NULL);
	i = 0;
	while (++i < len)
	{
		values[i - 1] = ft_atoi(array[i]);
		j = i - 1;
		while (--j >= 0)
		{
			if (values[j] == values[i - 1])
			{
				free(values);
				return (NULL);
			}
		}
	}
	return (values);
}

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
				execute(&a, &b);
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
