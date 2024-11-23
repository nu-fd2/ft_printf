/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:19:00 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/23 06:27:31 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_prints(const char *rei, va_list lain, int i)
{
	if (rei[i] == 's')
		return (ft_putstr(va_arg(lain, char *)));
	else if (rei[i] == 'c')
		return (ft_putchar(va_arg(lain, int)));
	else if (rei[i] == 'd' || rei[i] == 'i')
		return (ft_putnbr(va_arg(lain, int)));
	else if (rei[i] == 'u')
		return (ft_putchar(va_arg(lain,unsigned int)));
	else if (rei[i] == '%')
		return (ft_putchar('%'));
	else if (rei[i] == 'p')
		return (ft_puthex((unsigned long)va_arg(lain, void *), 1, 0));
	else if (rei[i] == 'x')
		return (ft_puthex(va_arg(lain, int), 0, 0));
	else if (rei[i] == 'X')
		return (ft_puthex(va_arg(lain, int), 0, 1));
	return (0);
}

int ft_printf(const char *rei, ...)
{
	int i, size;
	va_list lain;

	va_start(lain, rei);
	i = 0;
	size = 0;
	while(rei[i])
	{
		if (rei[i] == '%')
		{
			size += ft_prints(rei, lain, ++i);
			i++;
		}
		else
			size += ft_putchar(rei[i++]);
	}
	va_end(lain);
	return (size);
}
