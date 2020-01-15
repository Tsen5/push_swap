/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:22:08 by swann             #+#    #+#             */
/*   Updated: 2020/01/15 19:01:29 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tools.h"
#include "../includes/push_swap.h"

static void		print_stack(t_stack *stack)
{
	int		i;

	i = stack->size - 1;
	ft_putstr("STACK : ");
	while (i >= 0)
	{
		ft_putnbr(stack->values[i]);
		ft_putchar(' ');
		i--;
	}
	ft_putchar('\n');
}

int		findi_min_in(t_stack *stack, int start, int end)
{
	int		i;
	int		min;

	i = start;
	min = start;
	while (i <= end)
	{
		if (stack->values[i] < stack->values[min])
			min = i;
		i++;
	}
	return (min);
}

int		findi_max_in(t_stack *stack, int start, int end)
{
	int		i;
	int		max;

	i = start;
	max = start;
	while (i <= end)
	{
		if (stack->values[i] > stack->values[max])
			max = i;
		i++;
	}
	return (max);
}

int		findi_value_from(t_stack *stack, int start, int end, char *from)
{
	int		i;
	int		add;

	if (ft_strcmp(from, "up") == 0)
	{
		i = stack->size - 1;
		add = -1;
	}
	else
	{
		i = 0;
		add = 1;
	}
	while (i >= 0 && i < stack->size)
	{
		if (stack->values[i] >= start && stack->values[i] <= end)
		{
			ft_putstr("  - Return : ");
			ft_putnbrendl(stack->values[i]);
			return (i);
		}
		i += add;
	}
	return (-1);
}

void	tiny_sort(t_stack *a)
{
	if (a->size > 1)
	{
		if (a->values[0] < a->values[1])
		{
			ft_putendl_fd("sa", 1);
			swap(a);
		}
	}
}

void	small_sort_2(t_stack *a, t_stack *b, int min, int max)
{
	if ((min == 0 && (max == 1 || max == 2)) || (min == 1 && max == 0))
	{
		ft_putendl_fd("sa", 1);
		swap(a);
	}
	if ((min == 0 && max == 1) || (min == 1 && max == 2))
	{
		ft_putendl_fd("ra", 1);
		rotate(a, 0);
	}
	if ((min == 0 && max == 2) || (min == 2 && max == 1))
	{
		ft_putendl_fd("rra", 1);
		rotate(a, 1);
	}
	while (b->size > 0)
	{
		ft_putendl_fd("pa", 1);
		push(b, a);
	}
}

void	small_sort(t_stack *a, t_stack *b)
{
	int		min;
	int		max;

	while (a->size > 3)
	{
		while (findi_min_in(a, 0, a->size - 1) != (a->size - 1))
		{
			if ((findi_min_in(a, 0, a->size - 1) + 1) / 2 > a->size / 2)
			{
				ft_putendl_fd("rra", 1);
				rotate(a, 1);
			}
			else
			{
				ft_putendl_fd("ra", 1);
				rotate(a, 0);
			}
		}
		ft_putendl_fd("pb", 1);
		push(a, b);
	}
	min = findi_min_in(a, 0, 2);
	max = findi_max_in(a, 0, 2);
	small_sort_2(a, b, min, max);
}

int		find_interval(t_stack *stack, int nb_chunk)
{
	int		min;
	int		max;

	min = findi_min_in(stack, 0, stack->size - 1);
	max = findi_max_in(stack, 0, stack->size - 1);
	ft_putstr("MIN : ");
	ft_putnbrendl(stack->values[min]);
	ft_putstr("MAX : ");
	ft_putnbrendl(stack->values[max]);
	return ((stack->values[max] - stack->values[min]) / nb_chunk);
}

void	init_chunk(t_stack *stack, t_chunk *c)
{
	int		min_i;
	int		max_i;

	c->i = 0;
	c->nb = 5; // find_nb_chunk()
	c->gap = find_interval(stack, c->nb);
	min_i = findi_min_in(stack, 0, stack->size - 1);
	c->min = stack->values[min_i];
	max_i = findi_max_in(stack, 0, stack->size - 1);
	c->max = stack->values[max_i];

	ft_putendl("----------- INIT CHUNK -----------");	
	ft_putstr("NB : ");
	ft_putnbrendl(c->nb);
	ft_putstr("GAP : ");
	ft_putnbrendl(c->gap);
	ft_putstr("MIN : ");
	ft_putnbrendl(c->min);
	ft_putstr("MAX : ");
	ft_putnbrendl(c->max);
	ft_putendl("----------------------------------");	
}

int		geti_value(t_stack *a, t_chunk c)
{
	int		start;
	int		end;
	int		up_i;
	int		down_i;

	start = (c.i * c.gap) + c.min;
	end = (((c.i + 1) * c.gap) - 1) + c.min;
	ft_putendl("Treated gap :");
	ft_putstr("  - Start : ");
	ft_putnbrendl(start);
	ft_putstr("  - End : ");
	ft_putnbrendl(end);
	up_i = findi_value_from(a, start, end, "up");
	down_i = findi_value_from(a, start, end, "down");
	if ((up_i + 1) < a->size - down_i)
		return (up_i);
	else
		return (down_i);
}

void	push_i_to_b(t_stack *a, t_stack *b, int i)
{
	if (i < a->size / 2)
	{
		ft_putendl("  - Way : rra");
		while (i >= 0)
		{
			// ft_putendl_fd("rra", 1);
			rotate(a, 1);
			i--;
		}
	}
	else
	{
		ft_putendl("  - Way : ra");
		while (i < (a->size - 1))
		{
			// ft_putendl_fd("ra", 1);
			rotate(a, 0);
			i++;
		}
	}
	// ft_putendl_fd("pb", 1);
	ft_putstr("  - Pushed Value : ");
	ft_putnbrendl(a->values[a->size - 1]);
	push(a, b);
}

void	big_sort(t_stack *a, t_stack *b)
{
	int		i;
	t_chunk	c;

	init_chunk(a, &c);
	while (a->size > 0)
	{
		i = geti_value(a, c);
		if (i > -1)
			push_i_to_b(a, b, i);
		else
			c.i++;
		print_stack(a);
		print_stack(b);
		sleep(1);
	}
}

void	moves(t_stack *a, t_stack *b)
{
	if (a->size < 3)
		tiny_sort(a);
	else if (a->size >= 3 && a->size < 6)
		small_sort(a, b);
	else if (a->size >= 6 && a->size <= 100)
		big_sort(a, b);
	// else
	// 	insertion_sort(a, b);
	print_stack(a);
	print_stack(b);
}