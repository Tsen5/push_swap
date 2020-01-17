/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 00:58:54 by swann             #+#    #+#             */
/*   Updated: 2020/01/17 16:34:39 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tools.h"

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
		values[i - 1] = ft_atoi(array[len - i]);
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

void	remove_from_stack(t_stack *stack, int index)
{
	int		i;
	int		k;
	int		*news;

	if (stack->size <= 1)
		news = NULL;
	else
	{
		if (!(news = (int *)malloc(sizeof(int) * (stack->size - 1))))
			return ;
		i = 0;
		k = 0;
		while (i < stack->size)
		{
			if (i != index)
				news[i - k] = stack->values[i];
			else
				k++;
			i++;
		}
	}
	free(stack->values);
	stack->values = news;
	stack->size--;
}

void	add_to_stack(t_stack *stack, int elem, int index)
{
	int		i;
	int		k;
	int		*news;

	stack->size++;
	if (!(news = (int *)malloc(sizeof(int) * (stack->size))))
		return ;
	i = 0;
	k = 0;
	while (i < stack->size)
	{
		if (i != index)
			news[i] = stack->values[i - k];
		else
		{
			news[i] = elem;
			k++;
		}
		i++;
	}
	if (stack->size > 0)
		free(stack->values);
	stack->values = news;
}

void	clean_stack(t_stack *a, t_stack *b)
{
	if (a->size > 0)
	{
		free(a->values);
	}
	if (b->size > 0)
	{
		free(b->values);
	}
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