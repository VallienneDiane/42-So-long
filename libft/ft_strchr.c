/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:50:49 by dvallien          #+#    #+#             */
/*   Updated: 2021/11/10 14:14:49 by dvallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == 0)
	{
		while (str[i])
			i++;
		return (&((char *)str)[i]);
	}
	while (str[i])
	{
		if ((unsigned char)c == str[i])
			return ((char *) &str[i]);
		i++;
	}
	return (0);
}
