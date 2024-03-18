/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:37:45 by llitovuo          #+#    #+#             */
/*   Updated: 2024/03/18 15:59:06 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/**
 * @brief The fuction is designed to test the success of write function
 * 
 * @param len initial lenght of the string.
 * @param wlen written lenght.
 * @return int returns len + written lenght OR -1 if either has failed.
 */

static int	fail_check(int len, int wlen)
{
	if (wlen < 0 || len < 0)
		return (-1);
	else
		return (len + wlen);
}

/**
 * @brief The function guides args to right functions based on format specifier.
 * 
 * @param str the string that has the format specifiers.
 * @param args given va_list
 * @return int int returns written lenght
 */

static int	fs_sorter(const char *str, va_list args, int fd)
{
	int	wlen;

	wlen = 0;
	if (*str == 'c')
		wlen = ft_putchar_fprintf(va_arg(args, int), fd, wlen);
	else if (*str == 's')
		wlen = ft_putstr_fprintf(va_arg(args, char *), fd, wlen);
	else if (*str == 'p')
		wlen += ft_putptr_fprintf(va_arg(args, unsigned long long), \
		&wlen, "0123456789abcdef", fd);
	else if (*str == 'i' || *str == 'd')
		wlen += ft_putnbr_base_fprintf(va_arg(args, int), &wlen, \
		"0123456789", fd);
	else if (*str == 'u')
		wlen += ft_putnbr_base_fprintf(va_arg(args, unsigned int), \
		&wlen, "0123456789", fd);
	else if (*str == 'x')
		wlen += ft_putnbr_base_fprintf(va_arg(args, unsigned int), \
		&wlen, "0123456789abcdef", fd);
	else if (*str == 'X')
		wlen += ft_putnbr_base_fprintf(va_arg(args, unsigned int), \
		&wlen, "0123456789ABCDEF", fd);
	else if (*str == '%')
		wlen = ft_putchar_fprintf('%', fd, wlen);
	return (wlen);
}

/**
 * @brief The function prints cspdiuxX% conversions
 * 
 * @param str printed string with format specifiers
 * @param ... va_listed format specifiers
 * @return int the full lenght of printed string or -1 if failed.
 */

int	ft_fprintf(int fd, const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			len = fail_check(len, fs_sorter(str, args, fd));
			str++;
		}
		else
		{
			len = fail_check(len, ft_putchar_fprintf(*str, fd, 0));
			str++;
		}
		if (len < 0)
			break ;
	}
	va_end(args);
	if (len < 0)
		return (-1);
	return (len);
}
