/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbarrtostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegros <slegros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:00:33 by slegros           #+#    #+#             */
/*   Updated: 2018/03/12 18:09:35 by slegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dbarrtostr(char **dbarr)
{
	int		i;
	char	*str;

	i = -1;
	str = ft_strnew(0);
	while (dbarr[++i] != NULL)
	{
		str = ft_strjoinfree(str, dbarr[i], 1);
		if (dbarr[i + 1] != NULL)
			str = ft_strjoinfree(str, " ", 1);
	}
	return (str);
}
