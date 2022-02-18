/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:42:24 by dvallien          #+#    #+#             */
/*   Updated: 2021/11/10 16:53:18 by dvallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fill(int n, size_t count, char *str)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	str[count] = '\0';
	if (n == 0)
		str[count - 1] = '0';
	while (nbr > 0)
	{
		str[count - 1] = nbr % 10 + '0';
		nbr /= 10;
		count--;
	}
}

char	*ft_itoa(int n)
{
	size_t	count;
	char	*str;
	long	nbr;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	if (nbr == 0)
		count++;
	while (nbr > 0)
	{
		nbr /= 10;
		count ++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	ft_fill(n, count, str);
	return (str);
}
