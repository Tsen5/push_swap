/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 21:38:36 by swann             #+#    #+#             */
/*   Updated: 2020/01/06 12:04:17 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	char	*s;
	int		i;
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	i = 0;
	s = (char *)str;
	while (ft_isspace(s[i]) == 1)
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * sign);
}
