/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:01:52 by swann             #+#    #+#             */
/*   Updated: 2020/01/05 21:17:49 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (ft_strlen(str) > 1)
			i++;
		else
			return (0);
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
