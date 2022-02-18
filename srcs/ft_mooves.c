/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mooves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:33:19 by dvallien          #+#    #+#             */
/*   Updated: 2022/02/17 17:07:58 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_up(t_data *data)
{
	if (data->map->bidim[data->items->p_y - 1][data->items->p_x] == 'E')
		ft_win_game(data);
	else if (data->map->bidim[data->items->p_y - 1][data->items->p_x] != '1')
	{
		if (data->map->bidim[data->items->p_y - 1][data->items->p_x] == 'C')
			data->player->collectible++;
		data->map->bidim[data->items->p_y][data->items->p_x] = '0';
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->tile, data->items->p_x * 100, data->items->p_y * 100);
		data->map->bidim[data->items->p_y - 1][data->items->p_x] = 'P';
		data->items->p_y--;
		data->player->step++;
		printf("you made %d steps\n", data->player->step);
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->rayman1, data->items->p_x * 100, data->items->p_y * 100);
	}
}

void	ft_move_down(t_data *data)
{
	if (data->map->bidim[data->items->p_y + 1][data->items->p_x] == 'E')
		ft_win_game(data);
	else if (data->map->bidim[data->items->p_y + 1][data->items->p_x] != '1')
	{
		if (data->map->bidim[data->items->p_y + 1][data->items->p_x] == 'C')
			data->player->collectible++;
		data->map->bidim[data->items->p_y][data->items->p_x] = '0';
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->tile, data->items->p_x * 100, data->items->p_y * 100);
		data->map->bidim[data->items->p_y + 1][data->items->p_x] = 'P';
		data->items->p_y++;
		data->player->step++;
		printf("you made %d steps\n", data->player->step);
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->rayman1, data->items->p_x * 100, data->items->p_y * 100);
	}
}

void	ft_move_left(t_data *data)
{
	if (data->map->bidim[data->items->p_y][data->items->p_x - 1] == 'E')
		ft_win_game(data);
	else if (data->map->bidim[data->items->p_y][data->items->p_x - 1] != '1')
	{
		if (data->map->bidim[data->items->p_y][data->items->p_x - 1] == 'C')
			data->player->collectible++;
		data->map->bidim[data->items->p_y][data->items->p_x] = '0';
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->tile, data->items->p_x * 100, data->items->p_y * 100);
		data->map->bidim[data->items->p_y][data->items->p_x - 1] = 'P';
		data->items->p_x--;
		data->player->step++;
		printf("you made %d steps\n", data->player->step);
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->rayman1, data->items->p_x * 100, data->items->p_y * 100);
	}
}

void	ft_move_right(t_data *data)
{
	if (data->map->bidim[data->items->p_y][data->items->p_x + 1] == 'E')
		ft_win_game(data);
	else if (data->map->bidim[data->items->p_y][data->items->p_x + 1] != '1')
	{
		if (data->map->bidim[data->items->p_y][data->items->p_x + 1] == 'C')
			data->player->collectible++;
		data->map->bidim[data->items->p_y][data->items->p_x] = '0';
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->tile, data->items->p_x * 100, data->items->p_y * 100);
		data->map->bidim[data->items->p_y][data->items->p_x + 1] = 'P';
		data->items->p_x++;
		data->player->step++;
		printf("you made %d steps\n", data->player->step);
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->rayman1, data->items->p_x * 100, data->items->p_y * 100);
	}
}
