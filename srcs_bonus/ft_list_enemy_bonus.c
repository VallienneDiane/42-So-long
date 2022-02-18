/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:40:43 by dvallien          #+#    #+#             */
/*   Updated: 2022/02/05 16:34:41 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_anim_enemy(t_data *data)
{
	static int	j = 0;
	t_enemy		*enemy;

	enemy = *data->list_enemy;
	while (enemy)
	{
		if (!ft_strncmp(enemy->enemy_dir, "right", 5))
			ft_anim_enemy_right(data, enemy, j);
		if (!ft_strncmp(enemy->enemy_dir, "left", 4))
			ft_anim_enemy_left(data, enemy, j);
		enemy = enemy->next;
	}
	if (j == 6)
		j = 0;
	j++;
}

void	ft_anim_enemy_right(t_data *data, t_enemy *enemy, int j)
{
	if (j == 0)
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->enemy1, enemy->e_x * 100, enemy->e_y * 100);
	if (j == 3)
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->enemy2, enemy->e_x * 100, enemy->e_y * 100);
	if (j == 4)
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->enemy3, enemy->e_x * 100, enemy->e_y * 100);
	if (j == 5)
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->enemy4, enemy->e_x * 100, enemy->e_y * 100);
	if (j == 6)
		ft_moove_enemy_right(data, enemy);
}

void	ft_anim_enemy_left(t_data *data, t_enemy *enemy, int j)
{
	if (j == 0)
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->enemy5, enemy->e_x * 100, enemy->e_y * 100);
	if (j == 3)
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->enemy6, enemy->e_x * 100, enemy->e_y * 100);
	if (j == 4)
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->enemy7, enemy->e_x * 100, enemy->e_y * 100);
	if (j == 5)
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->enemy8, enemy->e_x * 100, enemy->e_y * 100);
	if (j == 6)
		ft_moove_enemy_left(data, enemy);
}

void	ft_moove_enemy_right(t_data *data, t_enemy *enemy)
{
	if (data->map->bidim[enemy->e_y][enemy->e_x] == \
	data->map->bidim[data->items->p_y][data->items->p_x])
		ft_loose_game(data);
	if (data->map->bidim[enemy->e_y][enemy->e_x + 1] == '1' \
	|| data->map->bidim[enemy->e_y][enemy->e_x + 1] == 'E' \
	|| data->map->bidim[enemy->e_y][enemy->e_x + 1] == 'C')
		enemy->enemy_dir = "left";
	else
	{
		data->map->bidim[enemy->e_y][enemy->e_x] = '0';
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->tile, enemy->e_x * 100, enemy->e_y * 100);
		data->map->bidim[enemy->e_y][enemy->e_x + 1] = 'H';
		enemy->e_x++;
	}
}

void	ft_moove_enemy_left(t_data *data, t_enemy *enemy)
{
	if (data->map->bidim[enemy->e_y][enemy->e_x] == \
	data->map->bidim[data->items->p_y][data->items->p_x])
		ft_loose_game(data);
	if (data->map->bidim[enemy->e_y][enemy->e_x - 1] == '1' \
	|| data->map->bidim[enemy->e_y][enemy->e_x - 1] == 'E' \
	|| data->map->bidim[enemy->e_y][enemy->e_x - 1] == 'C')
		enemy->enemy_dir = "right";
	else
	{
		data->map->bidim[enemy->e_y][enemy->e_x] = '0';
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->tile, enemy->e_x * 100, enemy->e_y * 100);
		data->map->bidim[enemy->e_y][enemy->e_x - 1] = 'H';
		enemy->e_x--;
	}
}
