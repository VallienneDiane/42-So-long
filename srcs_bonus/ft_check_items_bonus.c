/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_items_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:52:41 by dvallien          #+#    #+#             */
/*   Updated: 2022/02/17 17:12:15 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_items(t_data *data)
{
	data->items->start_position = 0;
	data->items->collectible = 0;
	data->items->exit = 0;
	data->player->step = 0;
	data->player->collectible = 0;
}

int	ft_check_nbr_items(t_data *data)
{
	if (data->items->collectible < 1)
	{
		ft_putstr_fd("Error : you need at least one collectible\n", 1);
		exit(EXIT_FAILURE);
	}
	if (data->items->exit < 1)
	{
		ft_putstr_fd("Error : you need at least one exit\n", 1);
		exit(EXIT_FAILURE);
	}
	if (data->items->start_position != 1)
	{
		ft_putstr_fd("Error : you need only one start position\n", 1);
		exit(EXIT_FAILURE);
	}
	return (1);
}

void	ft_go_end_map(char *map_ber)
{
	int	i;

	i = 0;
	while (map_ber[i])
		i++;
	ft_check_ber(map_ber, i);
}

void	ft_check_ber(char *map_ber, int i)
{
	i--;
	if (map_ber[i--] != 'r')
	{
		printf("Error : map extension must be .ber ");
		exit(EXIT_FAILURE);
	}
	if (map_ber[i--] != 'e')
	{
		printf("Error : map extension must be .ber ");
		exit(EXIT_FAILURE);
	}
	if (map_ber[i--] != 'b')
	{
		printf("Error : map extension must be .ber ");
		exit(EXIT_FAILURE);
	}
	if (map_ber[i--] != '.')
	{
		printf("Error : map extension must be .ber ");
		exit(EXIT_FAILURE);
	}
}
