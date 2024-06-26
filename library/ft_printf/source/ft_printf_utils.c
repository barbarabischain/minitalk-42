/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:55:52 by babischa          #+#    #+#             */
/*   Updated: 2024/02/04 11:20:19 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putnbr_fd(long nb, unsigned int base, char *letter, int fd)
{
	unsigned int	num;
	unsigned int	i;

	i = 0;
	num = nb;
	if (nb < 0 && base == 10)
	{
		num = -nb;
		i += ft_putchar_fd('-', fd);
	}
	if (num >= base)
	{
		i += ft_putnbr_fd((num / base), base, letter, fd);
		num = num % base;
	}
	if (num < base)
	{
		i += ft_putchar_fd(letter[num], fd);
	}
	return (i);
}

int	ft_put_ptr(unsigned long long nb, char *letter, int fd)
{
	unsigned long long	num;
	unsigned long long	i;

	i = 0;
	num = nb;
	if (num >= 16)
	{
		i += ft_put_ptr((num / 16), letter, fd);
		num = num % 16;
	}
	if (num < 16)
	{
		i += ft_putchar_fd(letter[num], fd);
	}
	return (i);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
		return (ft_printf_str("(nil)"));
	i += ft_printf_str("0x");
	i += ft_put_ptr(ptr, HEX_LOW, 1);
	return (i);
}
