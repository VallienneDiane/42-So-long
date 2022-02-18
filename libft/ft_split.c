/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:36:44 by dvallien          #+#    #+#             */
/*   Updated: 2021/11/13 10:14:41 by dvallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*ft_fill_tab(char *str, char *tab, size_t count_caracter, size_t i)
{
	size_t	a;
	size_t	index;

	if (count_caracter > 0)
	{
		tab = ft_calloc((count_caracter + 1), sizeof(char));
		if (!tab)
			return (NULL);
		a = 0;
		index = i - count_caracter;
		while (a < count_caracter && str[index + a])
		{
			tab[a] = str[index + a];
			a++;
		}
	}
	return (tab);
}

static void	ft_check_word(char *str, char c, char **tab)
{
	int	i;
	int	j;
	int	count_caracter;

	i = -1;
	j = 0;
	count_caracter = 0;
	while (str[++i])
	{
		if (str[i] != c)
			count_caracter++;
		else if (count_caracter > 0 || !str[i])
		{
			tab[j] = ft_fill_tab(str, tab[j], count_caracter, i);
			if (!tab[j++])
			{
				ft_free(tab);
				break ;
			}
			count_caracter = 0;
		}
	}
	tab[j] = ft_fill_tab(str, tab[j], count_caracter, i);
	if (!tab[j] && count_caracter > 0)
		ft_free(tab);
}

static size_t	ft_count_word(char const *str, char c)
{
	size_t	i;
	size_t	count;
	size_t	count_word;

	i = 0;
	count = 0;
	count_word = 0;
	while (str[i])
	{
		if (str[i] != c)
			count++;
		else if (count > 0)
		{
			count_word++;
			count = 0;
		}
		i++;
	}
	if (count > 0)
		count_word++;
	return (count_word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	word_index;

	if (!s)
		return (NULL);
	word_index = ft_count_word(s, c);
	tab = ft_calloc((word_index + 1), sizeof (char *));
	if (!tab)
		return (NULL);
	ft_check_word((char *)s, c, tab);
	return (tab);
}
