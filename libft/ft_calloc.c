/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:58:09 by dvallien          #+#    #+#             */
/*   Updated: 2022/02/17 14:12:06 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	allsize;

	allsize = size * count;
	ptr = malloc(allsize);
	if (!ptr)
		return (NULL);
	ft_bzero((void *)ptr, allsize);
	return ((void *)ptr);
}
