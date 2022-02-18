/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:13:12 by dvallien          #+#    #+#             */
/*   Updated: 2022/02/17 14:17:00 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_open_map(t_data *data, char *map_ber)
{
	int	fd;
	int	i;

	i = -1;
	fd = open(map_ber, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error : map opening failed\n", 1);
		exit(EXIT_FAILURE);
	}
	if (!ft_init_map(data, fd))
	{
		ft_putstr_fd("Error : map initialisation failed\n", 1);
		exit(EXIT_FAILURE);
	}
	if (close(fd) == -1)
	{
		ft_putstr_fd("Error : map closing failed\n", 1);
		exit(EXIT_FAILURE);
	}	
}

int	ft_init_map(t_data *data, int fd)
{
	char	*line;

	data->map->y = 0;
	data->map->onedim = ft_calloc(1, 1);
	if (!data->map->onedim)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	ft_empty_map(line);
	data->map->y++;
	while (line)
	{
		data->map->onedim = ft_strjoin(data->map->onedim, line);
		if (!data->map->onedim)
			exit(EXIT_FAILURE);
		free(line);
		line = get_next_line(fd);
		ft_empty_line(line);
		data->map->y++;
	}
	data->map->bidim = ft_split(data->map->onedim, '\n');
	if (!data->map->bidim)
		exit(EXIT_FAILURE);
	free(data->map->onedim);
	return (1);
}

void	ft_empty_map(char *line)
{
	if (!line || line[0] == '\n')
	{
		printf("Error : empty map or line\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_empty_line(char *line)
{
	if (line && line[0] == '\n')
	{
		printf("Error : empty line\n");
		exit(EXIT_FAILURE);
	}
}

int	ft_check_map_rectangular(t_data *data)
{
	int		i;
	size_t	len;

	i = -1;
	len = ft_strlen(data->map->bidim[0]);
	while (data->map->bidim[++i])
	{
		if (ft_strlen(data->map->bidim[i]) != len)
		{
			ft_putstr_fd("Error : map is not rectangular\n", 1);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
