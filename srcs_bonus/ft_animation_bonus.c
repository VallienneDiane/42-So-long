/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:41:46 by dvallien          #+#    #+#             */
/*   Updated: 2022/02/05 15:01:05 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_animation(t_data *data)
{
	ft_rayman_wait(data);
	ft_anim_enemy(data);
	ft_print_step(data);
	usleep(180000);
	return (0);
}

int	ft_create_list_enemy(t_data *data)
{
	t_enemy	**list_enemy;

	list_enemy = malloc(sizeof(t_enemy));
	if (!list_enemy)
		exit(EXIT_FAILURE);
	data->list_enemy = list_enemy;
	*data->list_enemy = NULL;
	return (0);
}

void	ft_rayman_wait(t_data *data)
{
	static int	i = 0;

	if (i == 0)
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
		data->img->rayman1, data->items->p_x * 100, \
		data->items->p_y * 100);
	if (i == 1)
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
		data->img->rayman2, data->items->p_x * 100, \
		data->items->p_y * 100);
	if (i == 2)
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
		data->img->rayman3, data->items->p_x * 100, \
		data->items->p_y * 100);
	if (i == 3)
		mlx_put_image_to_window(data->img->mlx, data->img->win, \
		data->img->rayman4, data->items->p_x * 100, \
		data->items->p_y * 100);
	i++;
	if (i > 3)
		i = 0;
}

void	ft_rayman_mooves(t_data *data)
{
	data->img->rayman1 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/rayman_up1.xpm", data->img->x, data->img->y);
	data->img->rayman2 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/rayman_up2.xpm", data->img->x, data->img->y);
	data->img->rayman3 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/rayman_up3.xpm", data->img->x, data->img->y);
	data->img->rayman4 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/rayman_up4.xpm", data->img->x, data->img->y);
}

void	ft_rayman_left(t_data *data)
{
	data->img->rayman1 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/rayman_left1.xpm", data->img->x, data->img->y);
	data->img->rayman2 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/rayman_left2.xpm", data->img->x, data->img->y);
	data->img->rayman3 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/rayman_left3.xpm", data->img->x, data->img->y);
	data->img->rayman4 = mlx_xpm_file_to_image(data->img->mlx, \
		"img/rayman_left4.xpm", data->img->x, data->img->y);
}
