/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:19:00 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/22 10:31:19 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

int ft_printf(const char *fr, ...)
{
	int i, arg;
	va_list lain;
	va_start(lain, fr);
	
	i = 0;
	while(fr[i])
	{
		if (fr[i] == '%')
		{
			if (fr[i + 1] == 's')
				ft_putstr_fd(va_arg(lain, char *), 1);
			else if (fr[i + 1] == 'c')
				ft_putchar_fd(va_arg(lain, char), 1);
			else if (fr[i + 1] == 'd' || fr[i + 1] == 'i')
				ft_putnbr_fd(va_arg(lain, int), 1);
			else if (fr[i + 1] == 'u')
				ft_putchar_fd(va_arg(lain,unsigned int), 1);
			else if (fr[i + 1] == '%')
				ft_putchar_fd('%', 1);
			// else if (fr[i + 1] == 'p')
			// 	ft_putadr(va_arg(lain, int));
			// else if (fr[i + 1] == 'x' || fr[i + 1] == 'X')
			// 	ft_puthex(va_arg(lain, int));
		}
		else
			ft_putchar_fd(fr[i], 1);
		i++;
	}
	va_end(lain);
	return 0;
}