/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fprintf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:21:36 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/18 15:57:06 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/**
 * @brief Modified ft_putchar with int parameter to follow how many 
 * characters are written. Returns the incremented lenght.
 * 
 * @param c character to be written
 * @param wlen int lenght that is incremented
 * @return int incremented ++len; returns -1 if fails.
 */

int	ft_putchar_fprintf(char c, int fd, int wlen)
{
	if (write(fd, &c, 1) < 0)
		return (-1);
	wlen++;
	return (wlen);
}
