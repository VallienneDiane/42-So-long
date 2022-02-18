/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:33:28 by dvallien          #+#    #+#             */
/*   Updated: 2022/02/17 16:59:40 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_hook(int keycode, t_data *data)
{	
	if (keycode == 13)
		ft_move_up(data);
	if (keycode == 1)
		ft_move_down(data);
	if (keycode == 0)
		ft_move_left(data);
	if (keycode == 2)
		ft_move_right(data);
	if (keycode == 53)
		ft_destroy_window(data);
	return (0);
}

void	ft_destroy_window(t_data *data)
{
	ft_free(data->map->bidim);
	mlx_destroy_window(data->img->mlx, data->img->win);
	exit(EXIT_SUCCESS);
}

void	ft_win_game(t_data *data)
{
	if (data->player->collectible == data->items->collectible)
	{
		printf("Well done, you win !\n");
		ft_key_hook(53, data);
	}
	printf("You need to collect all the items !\n");
}
