/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:54:47 by dvallien          #+#    #+#             */
/*   Updated: 2022/02/17 16:53:48 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		ft_putstr_fd("Error : invalid number of arguments", 1);
		exit(EXIT_FAILURE);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	ft_init_struct(data);
	ft_valid_map(data, av);
	data->img->mlx = mlx_init();
	data->img->win = mlx_new_window(data->img->mlx, \
	ft_strlen(data->map->bidim[0]) * 100, (data->map->y -1) * 100, "Rayman");
	ft_init_image(data);
	ft_print_image(data);
	mlx_hook(data->img->win, 2, 0, ft_key_hook, data);
	mlx_hook(data->img->win, 17, 0, ft_exit, data);
	mlx_loop(data->img->mlx);
	return (0);
}

void	ft_init_struct(t_data *data)
{
	t_map		*map;
	t_items		*items;
	t_img		*img;
	t_player	*player;

	map = malloc(sizeof(t_map));
	items = malloc(sizeof(t_items));
	img = malloc(sizeof(t_img));
	player = malloc(sizeof(t_player));
	if (!map || !items || !img || !player)
		exit(EXIT_FAILURE);
	data->map = map;
	data->items = items;
	data->img = img;
	data->player = player;
}

void	ft_valid_map(t_data *data, char **av)
{
	ft_open_map(data, av[1]);
	ft_go_end_map(av[1]);
	ft_check_map_rectangular(data);
	ft_check_string(data);
	ft_check_nbr_items(data);
}

int	ft_exit(t_data *data)
{
	ft_free(data->map->bidim);
	exit(EXIT_SUCCESS);
}

void	ft_free(char **bidim)
{
	int	i;

	i = -1;
	while (bidim[++i])
		free(bidim[i]);
	free(bidim);
}
