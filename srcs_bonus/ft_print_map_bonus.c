/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:08:56 by dvallien          #+#    #+#             */
/*   Updated: 2022/02/17 13:23:13 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_image(t_data *data)
{
	data->img->tile = mlx_xpm_file_to_image(data->img->mlx, \
		"img/tile_jungle.xpm", data->img->x, data->img->y);
	data->img->tree = mlx_xpm_file_to_image(data->img->mlx, \
		"img/trees.xpm", data->img->x, data->img->y);
	data->img->exit = mlx_xpm_file_to_image(data->img->mlx, \
		"img/exit.xpm", data->img->x, data->img->y);
	data->img->rayman1 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/rayman1.xpm", data->img->x, data->img->y);
	data->img->rayman2 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/rayman2.xpm", data->img->x, data->img->y);
	data->img->rayman3 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/rayman3.xpm", data->img->x, data->img->y);
	data->img->rayman4 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/rayman4.xpm", data->img->x, data->img->y);
	data->img->collect1 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/blue5.xpm", data->img->x, data->img->y);
	ft_init_image_enemy(data);
}

void	ft_init_image_enemy(t_data *data)
{
	data->img->enemy1 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/enemy1.xpm", data->img->x, data->img->y);
	data->img->enemy2 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/enemy2.xpm", data->img->x, data->img->y);
	data->img->enemy3 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/enemy3.xpm", data->img->x, data->img->y);
	data->img->enemy4 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/enemy4.xpm", data->img->x, data->img->y);
	data->img->enemy5 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/enemy1_left.xpm", data->img->x, data->img->y);
	data->img->enemy6 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/enemy2_left.xpm", data->img->x, data->img->y);
	data->img->enemy7 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/enemy3_left.xpm", data->img->x, data->img->y);
	data->img->enemy8 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/enemy4_left.xpm", data->img->x, data->img->y);
}

void	ft_print_image(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (data->map->bidim[++y])
	{
		x = 0;
		while (data->map->bidim[y][x])
		{
			ft_print_img(data, x, y);
			x++;
		}
	}
}

void	ft_print_img(t_data *data, int x, int y)
{
	if (data->map->bidim[y][x] == '1')
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->tree, x * 100, y * 100);
	if (data->map->bidim[y][x] == '0')
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->tile, x * 100, y * 100);
	if (data->map->bidim[y][x] == 'C')
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->collect1, x * 100, y * 100);
	if (data->map->bidim[y][x] == 'E')
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
			data->img->exit, x * 100, y * 100);
}

void	ft_print_step(t_data *data)
{
	char	*nbr_step;

	nbr_step = 0;
	nbr_step = ft_itoa(data->player->step);
	if (!nbr_step)
		exit(EXIT_FAILURE);
	mlx_string_put(data->img->mlx, data->img->win, (data->items->p_x * 100) \
	+ 7, (data->items->p_y * 100) + 15, 0x00FFFFFF, nbr_step);
	free(nbr_step);
}
