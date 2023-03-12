/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikadugar <erikadugar@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:12:39 by etavera-          #+#    #+#             */
/*   Updated: 2023/03/12 22:32:33 by erikadugar       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// # include <stdarg.h>
// # include <unistd.h>
// # include <stdlib.h>
// # include <stdio.h>

// int	ft_strlen(const char *str)
// {
// 	int	r;

// 	r = 0;
// 	while (str[r] != '\0')
// 	{
// 		r++;
// 	}
// 	return (r);
// }

// int	putstr(char const *str)
// {
// 	if (str == NULL)
// 		return (write(1, "(null)", 6));
// 	else
// 		return (write(1, str, ft_strlen(str)));
// }


// static size_t	i_digits(unsigned int n)
// {
// 	size_t	digits;

// 	digits = 0;
// 	if (n <= 0)
// 		digits += 1;
// 	while (n != 0)
// 	{
// 		n /= 10;
// 		digits += 1;
// 	}
// 	return (digits);
// }

// int	putunsigned(unsigned int a, int fd)
// {
// 	int	c;

// 	if (a == 2147483648)
// 	{
// 		write(fd, "2", 1);
// 		putunsigned(147483648, fd);
// 	}
// 	else if (a < 0)
// 	{
// 		write(fd, "-", 1);
// 		putunsigned(-a, fd);
// 	}
// 	else if (a >= 0 && a <= 9)
// 	{
// 		c = a + '0';
// 		write(fd, &c, 1);
// 	}
// 	else
// 	{
// 		c = (a % 10) + '0';
// 		putunsigned(a / 10, fd);
// 		write(fd, &c, 1);
// 	}
// 	return (i_digits(a));
// }

// static char	*rev(char *tab)
// {
// 	int	i;
// 	int	t;
// 	int size;

// 	size = ft_strlen(tab);
// 	i = 0;
// 	while (i < size / 2)
// 	{
// 		t = tab[i];
// 		tab[i] = tab[size - i - 1];
// 		tab[size - i - 1] = t;
// 	i++;
// 	}
// 	return (tab);
// }

// static int	h_digits(unsigned int n)
// {
// 	int	digits;

// 	digits = 2;
// 	if (n == 0)
// 		return (1);
// 	while (n != 0)
// 	{
// 		digits += 1;
// 		n /= 16;
// 	}
// 	return (digits) ;
// }

// void	ptr(unsigned long d, char *acum)
// {
//    char	mod;
// 	int		i;

// 	i = 0;

// 	while (d > 0)
// 		{
// 			mod = d % 16;
// 			if (mod <= 15 && mod >= 10)
// 			{
// 				mod = mod + 87;
// 				acum[i++] = mod;
// 			}
// 			else if (mod <= 9)
// 			{
// 				mod = mod + 48;
// 				acum[i++] = mod;
// 			}
// 			d = d / 16;
// 		}
// 		putstr(rev(acum));
// }

// int	putpointer(unsigned long d)
// {
// 	char	*acum;

//    acum = NULL;
//    acum = malloc(h_digits(d));
//    if (d == 0)
// 		putunsigned(0, 1);
// 	else
//    {
// 		write(1, "0x", 2);
// 		ptr(d, acum);
//    }
// 	free(acum);
// 	return (h_digits(d));
// }


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
		{
				return (putpointer(va_arg(ptr, unsigned long)));
		}
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

// int	main(void)
// {
// 	int a = 0;
// 	int *b = &a;
// 	printf("%p\n",b);
// 	// ft_printf("%x\n",b);
// 	ft_printf("%p\n",b);
// 	ft_printf(" %p ", 0);
// 	// printf(" %p ", -1);
// 	// // TEST(3, print(" %p ", 15));
// 	// // TEST(4, print(" %p ", 16));
// 	// // TEST(5, print(" %p ", 17));
// 	// // TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
// 	// // TEST(7, print(" %p %p ", INT_MIN, INT_MAX));
// 	// // TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));
// 	// // TEST(9, print(" %p %p ", 0, 0));
// }
