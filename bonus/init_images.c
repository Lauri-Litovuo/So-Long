/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:01:26 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/22 11:33:42 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

void	init_player_img(t_data *data)
{
	int		i;
	char	*paths[5];

	i = 0;
	paths[0] = P0;
	paths[1] = P1;
	paths[2] = P2;
	paths[3] = P3;
	paths[4] = P4;
	while (i < 5)
	{
		data->player_txt[i] = mlx_load_png(paths[i]);
		if (!data->player_txt[i])
			mlx_errors(data);
		data->player[i] = mlx_texture_to_image(data->mlx, data->player_txt[i]);
		if (!data->player[i])
			mlx_errors(data);
		mlx_delete_texture(data->player_txt[i]);
		i++;
	}
}

void	init_collectible_img(t_data *data)
{
	int		i;
	char	*paths[3];

	i = 0;
	paths[0] = C0;
	paths[1] = C1;
	paths[2] = C2;
	while (i < 3)
	{
		data->collectable_txt[i] = mlx_load_png(paths[i]);
		if (!data->collectable_txt[i])
			mlx_errors(data);
		data->collectable[i] = mlx_texture_to_image(data->mlx, data->collectable_txt[i]);
		if (!data->collectable[i])
			mlx_errors(data);
		mlx_delete_texture(data->collectable_txt[i]);
		i++;
	}
}

void init_exit_img(t_data * data)
{
	int	i;
	char *paths[2];

	paths[0] = X0;
	paths[1] = X1;
	i = 0;
	while (i < 2)
	{
		data->exit_txt[i] = mlx_load_png(paths[i]);
		if (!data->exit_txt[0])
			mlx_errors(data);
		data->exit[i] = mlx_texture_to_image(data->mlx, data->exit_txt[i]);
		if (!data->exit)
			mlx_errors(data);
		mlx_delete_texture(data->exit_txt[i]);
		i++;
	}	
}

void init_enemies(t_data *data)
{
	int	i;
	char *paths[2];

	paths[0] = E0;
	paths[1] = E1;
	i = 0;
	while (i < 2)
	{
		data->enemy_txt[2] = mlx_load_png(paths[i]);
		if (!data->enemy_txt[0])
			mlx_errors(data);
		data->enemy[i] = mlx_texture_to_image(data->mlx, data->enemy_txt[i]);
		if (!data->enemy)
			mlx_errors(data);
		mlx_delete_texture(data->enemy_txt[i]);
		i++;
	}
}

void init_floor_and_walls(t_data *data)
{
	data->floor_txt = mlx_load_png("textures/floor/floor.png");
	if (!data->floor_txt)
		mlx_errors(data);
	data->floor = mlx_texture_to_image(data->mlx, data->floor_txt);
	if (!data->floor)
		mlx_errors(data);
	mlx_delete_texture(data->floor_txt);
	data->wall_txt = mlx_load_png("textures/wall/wall2.png");
	if (!data->wall_txt)
		mlx_errors(data);
	data->wall = mlx_texture_to_image(data->mlx, data->wall_txt);
	if (!data->wall)
		mlx_errors(data);
	mlx_delete_texture(data->wall_txt);
}
