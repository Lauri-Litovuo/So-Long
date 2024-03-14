/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:51:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/14 12:53:58 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h> ////DELETE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# define TEXTURE_SIZE 50
# define COLL 'C'
# define EXITS 'E'
# define PLAYERS 'P'
# define WALL '1'
# define SPACE '0'
# define FILL '1'
# define SET "CEP10"

enum error
{
	FIL = 1,
	MLC = 2,
	OS_MAP = 3,
	WALLS = 4,
	REQ = 5,
	RECT = 6,
	PATH = 7
};

typedef struct s_start
{
	int	x_pos;
	int	y_pos;
}		t_start;

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
}			t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	t_map	*map_ptr;
	void	*win_ptr;
	void	*textures[5];
}			t_data;


void	free_data(t_data data);
void	free_2d_array_of_size(char **arr, int size);

void	ft_error(int errcode);

int		validate_map(char *file, t_map *map);

int		get_sizes_xy(char *file, t_map *map);
char	**get_map_copy(char *file, t_map *map);

int		check_path(char **map_copy, t_map *map);

#endif