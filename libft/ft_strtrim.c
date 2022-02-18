/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:36:27 by dvallien          #+#    #+#             */
/*   Updated: 2021/11/10 16:38:46 by dvallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_checkset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_malloc(size_t start, size_t end)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * (end - start + 1));
	return (ptr);
}

static char	*ft_filltab(size_t end, size_t start, char *str, char const *s1)
{
	size_t	i;

	i = 0;
	while (i < (end - start))
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;
	char	*str;

	start = 0;
	end = 0;
	if (!s1)
		return (NULL);
	while (ft_checkset(s1[start], set))
		start++;
	end = start;
	if (start == ft_strlen(s1))
		return (ft_calloc(1, 1));
	while (s1[end])
		end++;
	while (ft_checkset(s1[end - 1], set))
		end--;
	str = ft_malloc(start, end);
	if (!str)
		return (0);
	str = ft_filltab(end, start, str, s1);
	return (str);
}
