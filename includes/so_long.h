/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:21:51 by dvallien          #+#    #+#             */
/*   Updated: 2022/02/17 13:48:14 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_enemy
{
	int				e_x;
	int				e_y;
	char			*enemy_dir;
	struct s_enemy	*next;
}			t_enemy;

typedef struct s_player
{
	void	*sprite;
	int		step;
	int		collectible;	
}			t_player;

typedef struct s_map
{
	char	*onedim;
	char	**bidim;
	int		y;
	int		x;
}			t_map;

typedef struct s_items
{
	int	start_position;
	int	collectible;
	int	exit;
	int	p_x;
	int	p_y;
	int	e_x;
	int	e_y;
}	t_items;

typedef struct s_img
{
	void	*mlx;
	void	*win;
	void	*tree;
	void	*tile;
	void	*rayman1;
	void	*rayman2;
	void	*rayman3;
	void	*rayman4;
	void	*collect1;
	void	*exit;
	int		x[1];
	int		y[1];
	void	*enemy1;
	void	*enemy2;
	void	*enemy3;
	void	*enemy4;
	void	*enemy5;
	void	*enemy6;
	void	*enemy7;
	void	*enemy8;
}			t_img;

typedef struct s_data
{
	t_map		*map;
	t_items		*items;
	t_img		*img;
	t_player	*player;
	t_enemy		**list_enemy;
}			t_data;

int		main(int ac, char **av);
void	ft_init_struct(t_data *data);
void	ft_valid_map(t_data *data, char **av);
void	ft_open_map(t_data *data, char *map_ber);
int		ft_init_map(t_data *data, int fd);
int		ft_check_string(t_data *data);
int		ft_check_nbr_items(t_data *data);
void	ft_go_end_map(char *map_ber);
void	ft_check_ber(char *map_ber, int i);
int		ft_check_map_rectangular(t_data *data);
void	ft_init_items(t_data *data);
void	ft_empty_map(char *line);
void	ft_empty_line(char *line);
void	ft_error_outline(t_data *data);
void	ft_check_caracters(t_data *data, char c, int i, int j);

int		ft_key_hook(int keycode, t_data *data);
void	ft_init_image(t_data *data);
void	ft_print_image(t_data *data);
void	ft_destroy_window(t_data *data);
void	ft_print_img(t_data *data, int x, int y);
void	ft_change_img(t_data *data, char *direction);

int		ft_animation(t_data *data);
void	ft_move_up(t_data *data);
void	ft_rayman_left(t_data *data);
void	ft_rayman_mooves(t_data *data);
void	ft_rayman_wait(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_right(t_data *data);
void	ft_move_left(t_data *data);
void	ft_win_game(t_data *data);
void	ft_free(char **map_2d);
int		ft_exit(t_data *data);

// BONUS
void	ft_print_step(t_data *data);
int		ft_create_list_enemy(t_data *data);
void	ft_add_enemy(t_data *data, int i, int j);
void	ft_print_ennemy(t_data *data, int x, int y);
void	ft_init_image_enemy(t_data *data);
void	ft_anim_enemy(t_data *data);
void	ft_anim_enemy_right(t_data *data, t_enemy *enemy, int j);
void	ft_anim_enemy_left(t_data *data, t_enemy *enemy, int j);
void	ft_moove_enemy_right(t_data *data, t_enemy *enemy);
void	ft_moove_enemy_left(t_data *data, t_enemy *enemy);
void	ft_loose_enemy(t_data *data);
void	ft_loose_game(t_data *data);

#endif