/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:51:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/22 11:35:05 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# define TXT_SIZE 50
# define COLL 'C'
# define EXITS 'E'
# define PLAYER 'P'
# define WALL '1'
# define FLOOR '0'
# define FILL '1'
# define SET "CEP10"
# define P0 "textures/player/player.png"
# define P1 "textures/player/player2.png"
# define P2 "textures/player/player3.png"
# define P3 "textures/player/player4.png"
# define P4 "textures/player/player5.png"
# define C0 "textures/collectibles/collectable.png"
# define C1 "textures/collectibles/collectable2.png"
# define C2 "textures/collectibles/collectable3.png"
# define X0 "textures/exits/exit.png"
# define X1 "textures/exits/exit.png"
# define E0 "textures/enemy/enemy.png"
# define E1 "textures/enemy/enemy2.png"

typedef enum e_error
{
	FIL = 1,
	MLC = 2,
	OS_MAP = 3,
	WALLS = 4,
	REQ = 5,
	RECT = 6,
	PATH = 7
}	t_error;

typedef enum e_movement
{
	LEFT = 1,
	RIGHT = 2,
	UP = 3,
	DOWN = 4
}	t_movement;

typedef struct s_map
{
	int		size_x;
	int		size_y;
	int		collectibles;
	int		collectibles_fill;
	int		exit;
	int		exit_fill;
	int		player;
	int		max_x;
	int		max_y;
	int		x_pos;
	int		y_pos;
	char	**map_copy;
}			t_map;

typedef struct s_animation 
{
	t_list		*frames;
	int			frame_speed;
	double		accum;
	int			frame_num;
	int			direction;
	long int	frame_count;
}			t_animation;

typedef struct s_data
{
	void			*mlx;
	t_map			*map;
	void			*win;
	mlx_texture_t	*wall_txt;
	mlx_texture_t	*floor_txt;
	mlx_texture_t	*collectable_txt[3];
	mlx_texture_t	*player_txt[5];
	mlx_texture_t	*exit_txt[2];
	mlx_texture_t	*enemy_txt[2];	
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*collectable[3];
	mlx_image_t		*player[5];
	mlx_image_t		*exit[2];
	mlx_image_t		*enemy[2];
}			t_data;

void	free_data(t_data *data);
void	free_2d_array_of_size(char **arr, int size);
void	free_and_exit(t_data *data);

void	ft_error(int errcode);
void	mlx_errors(t_data *data);

int		validate_map(char *file, t_map *map);

int		get_sizes_xy(char *file, t_map *map);
char	**get_map_copy(char *file, t_map *map);

int		check_path(char **map_copy, t_map *map);

void	init_textures(t_data *data);
void	create_objects(t_data *data);
void	create_floor(t_data *data);
void	init_images(t_data *data);

void	key_hooking(mlx_key_data_t keydata, void *param);

void	init_player_img(t_data *data);
void	init_collectible_img(t_data *data);
void	init_exit_img(t_data * data);
void	init_enemies(t_data *data);
void	init_floor_and_walls(t_data *data);

#endif