/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:33:28 by dvallien          #+#    #+#             */
/*   Updated: 2022/02/17 11:10:47 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_hook(int keycode, t_data *data)
{	
	if (keycode == 13)
	{
		ft_change_img(data, "up");
		ft_move_up(data);
	}
	if (keycode == 1)
	{
		ft_change_img(data, "up");
		ft_move_down(data);
	}
	if (keycode == 0)
	{
		ft_change_img(data, "left");
		ft_move_left(data);
	}
	if (keycode == 2)
	{
		ft_change_img(data, "up");
		ft_move_right(data);
	}
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

void	ft_change_img(t_data *data, char *direction)
{
	if (!ft_strncmp(direction, "up", 2))
		ft_rayman_mooves(data);
	if (!ft_strncmp(direction, "left", 4))
		ft_rayman_left(data);
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

void	ft_loose_game(t_data *data)
{
	printf("Sorry, you loose, try again !\n");
	ft_key_hook(53, data);
}
