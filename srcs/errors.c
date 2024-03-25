/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:47:11 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/25 09:50:55 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_error(int errcode)
{
	if (errcode == FIL)
		write (2, "Error\nOpening file.\n", 20);
	else if (errcode == MLC)
		write (2, "Error\nMalloc failed\n", 20);
	else if (errcode == OS_MAP)
		write (2, "Error\nOversize map.\n", 20);
	else if (errcode == WALLS)
		write (2, "Error\nMap not surrounded by walls.\n", 35);
	else if (errcode == RECT)
		write (2, "Error\nMap is not rectangular.\n", 30);
	else if (errcode == REQ)
		write (2, "Error\nMap requirements not met.\n", 32);
	else if (errcode == PATH)
		write (2, "Error\nNo paths to win.\n", 23);
	else if (errcode == BER)
		write(2, "Error\nFile type not .ber\n", 25);
}

void	mlx_errors(t_data *data)
{
	ft_fprintf(2, "Error\n%s\n", mlx_errno);
	free_and_exit(data);
}
