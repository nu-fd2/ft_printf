/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:19:00 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/24 04:05:12 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prints(const char *rei, va_list lain, int i)
{
	char	*up;
	char	*down;

	up = "0123456789ABCDEF";
	down = "0123456789abcdef";
	if (rei[i] == 's')
		return (ft_putstr(va_arg(lain, char *)));
	else if (rei[i] == 'c')
		return (ft_putchar(va_arg(lain, int)));
	else if (rei[i] == 'd' || rei[i] == 'i')
		return (ft_putnbr((long)va_arg(lain, int)));
	else if (rei[i] == 'u')
		return (ft_putnbr((unsigned long)va_arg(lain, unsigned int)));
	else if (rei[i] == '%')
		return (ft_putchar('%'));
	else if (rei[i] == 'x')
		return (ft_puthex((unsigned int)va_arg(lain, void *), down));
	else if (rei[i] == 'X')
		return (ft_puthex((unsigned int)va_arg(lain, void *), up));
	else if (rei[i] == 'p')
		return (ft_putadr((unsigned long)va_arg(lain, void *)));
	return (0);
}

int	ft_printf(const char *rei, ...)
{
	int		i;
	int		size;
	va_list	lain;

	va_start(lain, rei);
	i = 0;
	size = 0;
	while (rei[i])
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
