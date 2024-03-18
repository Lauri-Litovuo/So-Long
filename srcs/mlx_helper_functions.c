/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:25:54 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/18 14:54:48 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	key_setup(mlx_key_data_t keydata, void *param)
{
	
}

void	init_textures(t_data *data)
{
	data->floor_txt = mlx_load_png("../textures/floor.png");
	if (!data->floor_txt)
		mlx_errors(data);
	data->wall_txt = mlx_load_png("../textures/wall.png");
	if (!data->wall_txt)
		mlx_errors(data);
	data->player_txt = mlx_load_png("../textures/player.png");
	if (!data->player_txt)
		mlx_errors(data);
	data->collectable_txt = mlx_load_png("../textures/collectable.png");
	if (!data->collectable_txt)
		mlx_errors(data);
	data->exit_txt = mlx_load_png("../textures/exit.png");
	if (!data->exit_txt)
		mlx_errors(data);
}
