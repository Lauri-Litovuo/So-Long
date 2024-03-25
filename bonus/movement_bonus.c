/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:45:24 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/25 16:11:39 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

static void	print_to_screen(t_data *data, int counter)
{
	char		*string;

	if (counter == 1)
		mlx_put_string(data->mlx, "Moves: ", \
	2, ((data->map->size_y + 1) * 50) - 25);
	if (data->text)
	{
		data->text->enabled = false;
		mlx_delete_image(data->mlx, data->text);
	}
	string = ft_itoa(counter);
	ft_printf("Moves: %d\n", counter);
	data->text = mlx_put_string(data->mlx, string, 70, \
	((data->map->size_y + 1) * 50) - 25);
	free(string);
}

static void	check_rules(t_data *data)
{
	int	i;

	i = 0;
	if (data->map->map_copy[data->map->y_pos][data->map->x_pos] == COLL)
	{
		while (data->map->collectibles_fill > 0)
		{
			if (data->collectable->instances[i].x / 50 == data->map->x_pos \
			&& data->collectable->instances[i].y / 50 == data->map->y_pos)
			{
				if (data->collectable->instances[i].enabled == true)
					data->map->collectibles_fill--;
				data->collectable->instances[i].enabled = false;
				break ;
			}
			i++;
		}
	}
	if (data->map->collectibles_fill == 0 \
	&& data->map->map_copy[data->map->y_pos][data->map->x_pos] == EXITS)
		mlx_close_window(data->mlx);
}

static int	allow_movement(int move, t_map *map, t_data *data)
{
	static int	counter;

	if (move == LEFT && map->map_copy[map->y_pos][map->x_pos - 1] != WALL)
	{
		print_to_screen(data, ++counter);
		map->x_pos -= 1;
	}
	else if (move == RIGHT && map->map_copy[map->y_pos][map->x_pos + 1] != WALL)
	{
		print_to_screen(data, ++counter);
		map->x_pos += 1;
	}
	else if (move == UP && map->map_copy[map->y_pos - 1][map->x_pos] != WALL)
	{
		print_to_screen(data, ++counter);
		map->y_pos -= 1;
	}
	else if (move == DOWN && map->map_copy[map->y_pos + 1][map->x_pos] != WALL)
	{
		print_to_screen(data, ++counter);
		map->y_pos += 1;
	}
	else
		return (0);
	return (1);
}

void	key_hooking(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (((keydata.key == MLX_KEY_A) || (keydata.key == MLX_KEY_LEFT)) \
	&& keydata.action == MLX_PRESS)
		if (allow_movement(LEFT, data->map, data) == 1)
			data->player->instances[0].x -= 50;
	if ((keydata.key == MLX_KEY_D || (keydata.key == MLX_KEY_RIGHT)) \
	&& keydata.action == MLX_PRESS)
		if (allow_movement(RIGHT, data->map, data) == 1)
			data->player->instances[0].x += 50;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) \
	&& keydata.action == MLX_PRESS)
		if (allow_movement(UP, data->map, data) == 1)
			data->player->instances[0].y -= 50;
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) \
	&& keydata.action == MLX_PRESS)
		if (allow_movement(DOWN, data->map, data) == 1)
			data->player->instances[0].y += 50;
	check_rules(data);
}
