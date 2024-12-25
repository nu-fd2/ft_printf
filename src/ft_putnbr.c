/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 04:38:24 by oel-mado          #+#    #+#             */
/*   Updated: 2024/12/25 20:37:06 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(long nbr)
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
