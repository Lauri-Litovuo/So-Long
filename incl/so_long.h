/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:51:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/02/23 11:35:05 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_map t_map
{
	int	size_x;
	int	size_y;
}			t_map;

typedef struct s_data t_data
{
	void	*mlx_ptr;
	t_map	*map_ptr;
	void	*win_ptr;
	void	*textures[5] //put how many sprites
	
}			t_data;

#endif