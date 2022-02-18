/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:38:07 by dvallien          #+#    #+#             */
/*   Updated: 2022/02/05 15:47:05 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_string(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	ft_init_items(data);
	while (data->map->bidim[++i])
	{
		if (data->map->bidim[i][0] != '1' \
		|| data->map->bidim[i][ft_strlen(data->map->bidim[i]) - 1] != '1')
			ft_error_outline(data);
		j = -1;
		while (data->map->bidim[i][++j])
		{
			if ((i == 0 || i == ft_strlen2d(data->map->bidim) - 1) \
			&& data->map->bidim[i][j] != '1')
				ft_error_outline(data);
			ft_check_caracters(data, data->map->bidim[i][j], i, j);
		}
	}
	return (0);
}

void	ft_error_outline(t_data *data)
{
	(void)data;
	ft_putstr_fd("Error : map outline should have only number 1\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_check_caracters(t_data *data, char c, int i, int j)
{
	if ((c != '1') && (c != '0') && (c != 'P')
		&& (c != 'C') && (c != 'E') && (c != 'H'))
	{
		ft_putstr_fd("Error : caracter forbidden\n", 1);
		exit(EXIT_FAILURE);
	}
	if (c == 'C')
		data->items->collectible++;
	if (c == 'P')
	{
		data->items->start_position++;
		data->items->p_x = j;
		data->items->p_y = i;
	}
	if (c == 'E')
		data->items->exit++;
	if (c == 'H')
		ft_add_enemy(data, i, j);
}

void	ft_add_enemy(t_data *data, int i, int j)
{
	t_enemy	*new_enemy;

	new_enemy = malloc(sizeof(t_enemy));
	if (!new_enemy)
		exit(EXIT_FAILURE);
	new_enemy->e_x = j;
	new_enemy->e_y = i;
	new_enemy->enemy_dir = "right";
	new_enemy->next = *data->list_enemy;
	*data->list_enemy = new_enemy;
}
