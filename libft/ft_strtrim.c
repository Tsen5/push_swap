/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swann <swann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 23:10:55 by slegros           #+#    #+#             */
/*   Updated: 2020/01/06 12:02:52 by swann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;

	if (s)
	{
		i = 0;
		while (ft_isspace(s[i]) == 1)
			i++;
		if (s[i] == '\0')
			return (ft_strnew(0));
		j = i;
		while (s[j] != '\0')
			j++;
		while (ft_isspace(s[j - 1]) == 1)
			j--;
		j--;
		return (ft_strsub(s, i, (j - i) + 1));
	}
	return (NULL);
}
