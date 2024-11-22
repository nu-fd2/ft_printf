/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:45:28 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/22 16:28:49 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

static int	ft_intlen(int nbr)
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

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (12);
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
