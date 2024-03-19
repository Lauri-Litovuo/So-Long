/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:45:24 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/19 15:23:34 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"



static int	allow_movement(int move, t_map *map)
{
	static int	counter;

	if (move == LEFT && map->map_copy[map->y_pos][map->x_pos - 1] != WALL)
	{
		ft_printf("Moves: %d\n", ++counter);
		map->x_pos -= 1;
	}
	else if (move == RIGHT && map->map_copy[map->y_pos][map->x_pos + 1] != WALL)
	{
		ft_printf("Moves: %d\n", ++counter);
		map->x_pos += 1;
	}
	else if (move == UP && map->map_copy[map->y_pos - 1][map->x_pos] != WALL)
	{
		ft_printf("Moves: %d\n", ++counter);
		map->y_pos -= 1;
	}
	else if (move == DOWN && map->map_copy[map->y_pos + 1][map->x_pos] != WALL)
	{
		ft_printf("Moves: %d\n", ++counter);
		map->y_pos += 1;
	}
	else
		return (0);
	return (1);
}

void	key_hooking(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) \
	&& keydata.action == MLX_PRESS)
		if (allow_movement(LEFT, data->map) == 1)
			data->player->instances[0].x -= 50;
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) \
	&& keydata.action == MLX_PRESS)
		if (allow_movement(RIGHT, data) == 1)
			data->player->instances[0].x += 50;
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) \
	&& keydata.action == MLX_PRESS)
		if (allow_movement(UP, data) == 1)
			data->player->instances[0].y -= 50;
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) \
	&& keydata.action == MLX_PRESS)
		if (allow_movement(DOWN, data) == 1)
			data->player->instances[0].y += 50;
}

