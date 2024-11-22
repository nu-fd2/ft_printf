/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:19:00 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/22 01:38:51 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

int ft_printf(const char *fr, ...)
{
	int i, arg;
	va_list lain;
	va_start(lain, fr);
	
	while(fr[i])
	{
		if (fr[i] == '%')
		{
			if (fr[i + 1] == 's')
			{
				arg = va_arg(lain, char *);
				ft_putstr_fd(arg, 1);
			}
			// else if (fr[i + 1] == 'p')
			// {
			// 	ft_putadr(arg);
			// 	arg = va_arg(lain, int);
			// }
			else if (fr[i + 1] == 'c')
			{
				arg = va_arg(lain, char);
				ft_putchar_fd(arg, 1);
			}
			else if (fr[i + 1] == 'd' || fr[i + 1] == 'i')
			{
				arg = va_arg(lain, int);
				ft_putnr_fd(arg, 1);
			}
			else if (fr[i + 1] == '%')
				ft_putchar_fd('%', 1);
			// else if (fr[i + 1] == 'x' || fr[i + 1] == 'X')
			// {
			// 	ft_puthex(arg);
			// 	arg = va_arg(lain, int);
			// }
		}
		else
			ft_putchar_fd(fr[i], 1);
		i++;
	}
	va_end(lain);
	return 0;
}