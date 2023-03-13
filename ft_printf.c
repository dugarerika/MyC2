/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:12:39 by etavera-          #+#    #+#             */
/*   Updated: 2023/03/13 12:04:55 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_specifier(const char spcr, va_list ptr)
{
	char	c;

	if (spcr == 'i' || spcr == 'd')
		return (putnbr(va_arg(ptr, int), 1));
	else if (spcr == 'c')
	{
		c = va_arg(ptr, int);
		return (write (1, &c, 1));
	}
	else if (spcr == 's')
		return (putstr(va_arg(ptr, char *)));
	else if (spcr == 'p')
	{
		if (ptr)
			return (putpointer(va_arg(ptr, unsigned long long)));
		else
			return (putstr("(nil)"));
	}
	else if (spcr == 'u')
		return (putunsigned(va_arg(ptr, unsigned int), 1));
	else if (spcr == 'x' || spcr == 'X')
		return (puthex(va_arg(ptr, unsigned int), spcr));
	else if (spcr == '%')
		return (write (1, "%", 1));
	return (0);
}

int	ft_printf(const char *fstr, ...)
{
	va_list	ptr;
	int		i;
	int		j;

	va_start(ptr, fstr);
	i = 0;
	j = 0;
	if (!fstr)
		return (0);
	while (fstr[i])
	{
		if (fstr[i] == '%')
		{
			i++;
			j += ft_check_specifier(fstr[i], ptr);
		}
		else
			j += write(1, &fstr[i], 1);
		i++;
	}
	va_end(ptr);
	return (j);
}
