/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fprintf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:54:34 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/18 15:50:36 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/**
 * @brief 
 * 
 * @param nbr the number to be written.
 * @param wlen the variable used to count written lenght
 * @param base base number, so eiher 2, 8, 10, 16
 * @param base_symbols the string (lenght of base number) of symbols 
 * that are used in conversion.
 * @return int returns the lenght written.
 */

int	ft_putnbr_base_fprintf(long int nbr, int *wlen, char *base_symbols, int fd)
{
	long long	long_nbr;
	int			base;

	long_nbr = nbr;
	base = ft_strlen(base_symbols);
	if (long_nbr < 0)
	{
		long_nbr = -long_nbr;
		if (ft_putchar_fprintf('-', fd, 0) < 0)
			return (-1);
		*wlen += 1;
	}
	if (long_nbr >= base)
	{
		if (ft_putnbr_base_fprintf(long_nbr / base, wlen, base, base_symbols) \
		< 0)
			return (-1);
		*wlen += 1;
	}
	if (ft_putchar_fprintf(base_symbols[long_nbr % base], fd, 0) < 0)
		return (-1);
	return (1);
}
