/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:11:11 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/26 12:59:54 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	place_object(char c, t_data *data, int i, int j)
{
	if (c == WALL)
		if (mlx_image_to_window \
		(data->mlx, data->wall, TXT_SIZE * j, TXT_SIZE * i) < 0)
			mlx_errors(data);
	if (c == COLL)
		if (mlx_image_to_window \
		(data->mlx, data->collectable, TXT_SIZE * j, TXT_SIZE * i) < 0)
			mlx_errors(data);
	if (c == EXITS)
		if (mlx_image_to_window \
		(data->mlx, data->exit, TXT_SIZE * j, TXT_SIZE * i) < 0)
			mlx_errors(data);
}
