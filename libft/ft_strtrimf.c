/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:38:08 by jukuntzm          #+#    #+#             */
/*   Updated: 2020/01/06 12:03:20 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimf(char *s)
{
	unsigned int	i;
	unsigned int	j;

	if (s)
	{
		i = 0;
		while (ft_isspace(s[i]) == 1)
			i++;
		if (s[i] == '\0')
		{
			free(s);
			return (ft_strnew(0));
		}
		j = i;
		while (s[j] != '\0')
			j++;
		while (ft_isspace(s[j - 1]) == 1)
			j--;
		j--;
		free(s);
		return (ft_strsub(s, i, (j - i) + 1));
	}
	return (NULL);
}
