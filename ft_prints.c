/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:45:28 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/24 04:00:57 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

static int	ft_intlen(long nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
		i++;
	while (nbr >= 10 || nbr <= -10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n <= 0)
	{
		if (n == 0)
		{
			ft_putchar('0');
			return (1);
		}
		ft_putchar('-');
		ft_putnbr(-n);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	return (ft_intlen(n));
}

static int	ft_strlen(const char *who)
{
	int	ask;

	ask = 0;
	while (who[ask])
		ask++;
	return (ask);
}

int	ft_puthex(unsigned long n, const char *base)
{
	unsigned long	len;
	int				i;

	len = ft_strlen(base);
	i = 0;
	if (n >= len)
	{
		i += ft_puthex(n / len, base);
		i += ft_putchar(base[n % len]);
	}
	else
		i += ft_putchar(base[n]);
	return (i);
}

int	ft_putadr(unsigned long n)
{
	int	i;

	i = 0;
	ft_putstr("0x");
	i += 2;
	i += ft_puthex(n, "0123456789abcdef");
	return (i);
}
