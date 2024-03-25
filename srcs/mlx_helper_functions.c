/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:25:54 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/25 10:17:02 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	init_textures(t_data *data)
{
	data->wall_txt = mlx_load_png("textures/wall/wall2.png");
	if (!data->wall_txt)
		mlx_errors(data);
	data->player_txt = mlx_load_png("textures/player/player.png");
	if (!data->player_txt)
		mlx_errors(data);
	data->floor_txt = mlx_load_png("textures/floor/floor.png");
	if (!data->floor_txt)
		mlx_errors(data);
	data->collectable_txt = \
	mlx_load_png("textures/collectibles/collectable.png");
	if (!data->collectable_txt)
		mlx_errors(data);
	data->exit_txt = mlx_load_png("textures/exits/exit.png");
	if (!data->exit_txt)
		mlx_errors(data);
}

void	init_images(t_data *data)
{
	data->floor = mlx_texture_to_image(data->mlx, data->floor_txt);
	if (!data->floor)
		mlx_errors(data);
	data->wall = mlx_texture_to_image(data->mlx, data->wall_txt);
	if (!data->wall)
		mlx_errors(data);
	data->player = mlx_texture_to_image(data->mlx, data->player_txt);
	if (!data->player)
		mlx_errors(data);
	data->collectable = \
	mlx_texture_to_image(data->mlx, data->collectable_txt);
	if (!data->collectable)
		mlx_errors(data);
	data->exit = mlx_texture_to_image(data->mlx, data->exit_txt);
	if (!data->exit)
		mlx_errors(data);
	mlx_delete_texture(data->floor_txt);
	mlx_delete_texture(data->wall_txt);
	mlx_delete_texture(data->player_txt);
	mlx_delete_texture(data->collectable_txt);
	mlx_delete_texture(data->exit_txt);
}

void	create_floor(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->size_y)
	{
		j = 0;
		while (j < data->map->size_x)
		{
			mlx_image_to_window \
			(data->mlx, data->floor, TXT_SIZE * j, TXT_SIZE * i);
			j++;
		}
		i++;
	}
}

void	create_objects(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->size_y)
	{
		j = 0;
		while (j < data->map->size_x)
		{
			if (data->map->map_copy[i][j] == WALL)
				mlx_image_to_window \
				(data->mlx, data->wall, TXT_SIZE * j, TXT_SIZE * i);
			if (data->map->map_copy[i][j] == COLL)
				mlx_image_to_window \
				(data->mlx, data->collectable, TXT_SIZE * j, TXT_SIZE * i);
			if (data->map->map_copy[i][j] == EXITS)
				mlx_image_to_window \
				(data->mlx, data->exit, TXT_SIZE * j, TXT_SIZE * i);
			j++;
		}
		i++;
	}
}

void	create_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->size_y)
	{
		j = 0;
		while (j < data->map->size_x)
		{
			if (data->map->map_copy[i][j] == PLAYER)
				mlx_image_to_window \
				(data->mlx, data->player, TXT_SIZE * j, TXT_SIZE * i);
			j++;
		}
		i++;
	}
}
