/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:47:11 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/08 15:39:33 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_error(int errcode)
{
	if (errcode == FIL)
		write (2, "Error\nOpening file.", 19);
	else if (errcode == MLC)
		write (2, "Error\nMalloc failed", 19);
	else if (errcode == MLC)
		write (2, "Error\nMalloc failed", 19);
	else if (errcode == OS_MAP)
		write (2, "Error\nOversize map.", 19);
	else if (errcode == WALLS)
		write (2, "Error\nMap not surrounded by walls.", 34);
	else
		write (2, "Error\nMap requirements not met.\n", 32);
}
