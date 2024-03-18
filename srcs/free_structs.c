/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:48:24 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/18 10:09:19 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"


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
	free_2d_array_of_size(data->map_ptr->map_copy, data->map_ptr->size_y);
	free(data->mlx_ptr);
	free(data->win_ptr);
	free(data->map_ptr);
	free(data);
}

void	free_and_exit(t_data *data)
{
	free_data(data);
	exit(1);
}

