/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:51:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/08 10:58:32 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# define TEXTURE_SIZE 50
# define COLL 'C'
# define EXITS 'E'
# define PLAYERS 'P'
# define WALL 1
# define SPACE 0

enum errors
{
	FIL = 1,
	MLC = 2,
	OS_MAP = 3,
	WALLS = 4,
}

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
	int		exit;
	int		player;
	t_start	start;
	int		max_x;
	int		max_y;
}			t_map;

/*change textures based on the size*/
typedef struct s_data
{
	void	*mlx_ptr;
	t_map	*map_ptr;
	void	*win_ptr;
	void	*textures[5];
}			t_data;

#endif