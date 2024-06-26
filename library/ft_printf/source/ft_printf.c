/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:39:45 by babischa          #+#    #+#             */
/*   Updated: 2024/02/04 11:13:54 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		i += write(1, "(null)", 6);
	else
	{
		while (*s)
			i += ft_putchar_fd(*s++, 1);
	}
	return (i);
}

int	ft_type(char token, va_list args)
{
	int	i;

	i = 0;
	if (token == 'c')
		i += ft_putchar_fd(va_arg(args, int), 1);
	else if (token == 's')
		i += ft_printf_str(va_arg(args, char *));
	else if (token == 'd' || token == 'i')
		i += ft_putnbr_fd(va_arg(args, int), 10, HEX_LOW, 1);
	else if (token == 'x')
		i += ft_putnbr_fd(va_arg(args, int), 16, HEX_LOW, 1);
	else if (token == 'X')
		i += ft_putnbr_fd(va_arg(args, int), 16, HEX_UP, 1);
	else if (token == 'u')
		i += ft_putnbr_fd(va_arg(args, unsigned int), 10, HEX_LOW, 1);
	else if (token == '%')
		i += write(1, "%", 1);
	else if (token == 'p')
		i += ft_print_ptr(va_arg(args, unsigned long long));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	if (!str)
		return (-1);
	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			i += ft_type((*++str), args);
		else
			i += ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return (i);
}
