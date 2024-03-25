/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:48:24 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/25 14:47:35 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

void	free_2d_array_of_size(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_data(t_data *data)
{
	free_2d_array_of_size(data->map->map_copy, data->map->size_y);
	free(data->map);
	free(data);
}

void	free_and_exit(t_data *data)
{
	free_data(data);
	exit(1);
}
