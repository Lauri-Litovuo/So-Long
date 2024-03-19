/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:51:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/19 15:16:42 by llitovuo         ###   ########.fr       */
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
	t_start	start;
	int		max_x;
	int		max_y;
	int		x_pos;
	int		y_pos;
	char	**map_copy;
}			t_map;

typedef struct s_data
{
	void			*mlx;
	t_map			*map;
	void			*win;
	mlx_texture_t	*wall_txt;
	mlx_texture_t	*floor_txt;
	mlx_texture_t	*collectable_txt;
	mlx_texture_t	*player_txt;
	mlx_texture_t	*exit_txt;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*collectable;
	mlx_image_t		*player;
	mlx_image_t		*exit;
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



#endif