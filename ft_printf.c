/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikadugar <erikadugar@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:12:39 by etavera-          #+#    #+#             */
/*   Updated: 2023/03/07 14:57:44 by erikadugar       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	h_digits(unsigned int n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits);
}

void	hex(unsigned int d, char base)
{
	char	mod;
	char	*acum;
	int		i;
	int		r;

	i = -1;
	r = d;
	acum = NULL;
	while (r != 0)
	{
		r = r / 16;
		i++;
	}
	acum = malloc(i);
	if (d == 0)
		putunsigned(d, 1);
	else
	{
		while (d > 0)
		{
			mod = d % 16;
			if (mod <= 15 && mod >= 10)
			{
				if (base == 'X')
				{
					// write(1, "0X", 1);
					mod = mod + 55;
				}
				else if (base == 'x')
				{
					// write(1, "0x", 1);
					mod = mod + 87;
				}
				acum[i] = mod;
				i--;
			}
			else if (mod <= 9)
			{
				mod = mod + 48;
				acum[i] = mod;
				i--;
			}
			d = d / 16;
		}
		putstr(acum);
	}
	free(acum);
}

int	put_hex(unsigned int d, char base)
{
	hex(d, base);
	return (h_digits(d));
}



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
		write(1, "pointer address", 11);
	else if (spcr == 'u')
		return (putunsigned(va_arg(ptr, unsigned int), 1));
	else if (spcr == 'x' || spcr == 'X')
		return (put_hex(va_arg(ptr, unsigned int), spcr));
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

// int	main(void)
// {
// 	printf(" %u ", -9);
// 	printf(" %u ", -10);
// 	printf(" %u ", -11);
// 	printf(" %u ", -14);
// 	printf(" %u ", -15);
// 	printf(" %u ", -16);
// 	printf(" %u ", -99);
// 	printf(" %u ", -100);
// 	printf(" %u ", -101);
// }
