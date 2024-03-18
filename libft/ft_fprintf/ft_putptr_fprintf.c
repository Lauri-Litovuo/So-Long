/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fprintf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:59:22 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/18 15:55:23 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putptr_fprintf(unsigned long long nbr, int *wlen, char *b_symb, int fd)
{
	if (*wlen == 0)
	{
		if (ft_putstr_fprintf("0x", fd, 0) < 0)
			return (-1);
		*wlen += 2;
	}
	if (nbr == 0)
	{
		if (ft_putchar_fprintf('0', fd, 0) < 0)
			return (-1);
		return (1);
	}
	if (nbr >= 16)
		*wlen += ft_putptr_fprintf(nbr / 16, wlen, b_symb, fd);
	if (ft_putchar_fprintf(b_symb[nbr % 16], fd, 0) < 0)
		return (-1);
	return (1);
}
