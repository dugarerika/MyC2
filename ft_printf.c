/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikadugar <erikadugar@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:12:39 by etavera-          #+#    #+#             */
/*   Updated: 2023/03/11 14:57:32 by erikadugar       ###   ########.fr       */
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
// 	printf("system 42: %x \n", 42);
// 	ft_printf("mine 42: %x \n", 42);
// 	printf("system -42: %x \n", -42);
// 	ft_printf("mine -42: %x \n", -42);
// 	printf("system 0: %x \n", 0);
// 	ft_printf("mine 0: %x \n", 0);
// 	printf("system 1: %x \n", 1);
// 	ft_printf("mine 1: %x \n", 1);
// 	printf("system -2: %x \n", -2);
// 	ft_printf("mine -2: %x \n", -2);
// 	printf("system 16: %x \n", 16);
// 	ft_printf("mine 16: %x \n", 16);
// printf("system: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// ft_printf("mine  : %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// printf("system: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\n", 'A', "42", 42, 42 ,42 , 42, 42);
// ft_printf("mine  : %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\n", 'A', "42", 42, 42 ,42 , 42, 42);
// printf("system: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// ft_printf("mine  : %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// 	// printf("system 0: %x \n", 0);
// 	// ft_printf("mine 0: %x \n", 0);
// 	// printf("system 1: %x \n", 1);
// 	// ft_printf("mine 1: %x \n", 1);
// 	// printf("system 9: %x \n", 9);
// 	// ft_printf("mine 9: %x \n", 9);
// 	// printf("system 10: %x \n", 10);
// 	// ft_printf("mine 10: %x \n", 10);
// 	// printf("system 11: %x \n", 11);
// 	// ft_printf("mine 11: %x \n", 11);
// 	// printf("system 15: %x \n", 15);
// 	// ft_printf("mine 15: %x \n", 15);
// 	// printf("system 16: %x \n", 16);
// 	// ft_printf("mine 16: %x \n", 16);
// 	// printf("system 17: %x \n", 17);
// 	// ft_printf("mine 17:  %x \n", 17);
// 	// printf("system 42: %x \n", 42);
// 	// ft_printf("mine 42: %x \n", 42);
// 	// printf("system 99: %x \n", 99);
// 	// ft_printf("mine 99:  %x \n", 99);
// 	// printf("system 100: %x \n", 100);
// 	// ft_printf("mine 100: %x \n", 100);
// 	// printf("system 101: %x \n", 101);
// 	// ft_printf("mine 101: %x \n", 101);
// 	// printf("system -1: %x \n", -1);
// 	// ft_printf("mine -1: %x \n", -1);
// 	// printf("system -2: %x \n", -2);
// 	// ft_printf("mine -2: %x \n", -2);
// 	// printf("system -1: %x \n", -3);
// 	// ft_printf("mine -1: %x \n", -3);
// 	// printf("system -1: %x \n", -4);
// 	// ft_printf("mine -1: %x \n", -4);
// 	// printf("system -1: %x \n", -5);
// 	// ft_printf("mine -1: %x \n", -5);
// 	// printf("system -9: %x \n", -9);
// 	// ft_printf("mine -9: %x \n", -9);
// 	// printf("system -10: %x \n", -10);
// 	// ft_printf("mine -10: %x \n", -10);
// 	// printf("system -11: %x \n", -11);
// 	// ft_printf("mine -11: %x \n", -11);
// 	// printf("system -14: %x \n", -14);
// 	// ft_printf("mine -14: %x \n", -14);
// 	// printf("system -15: %x \n", -15);
// 	// ft_printf("mine -15: %x \n", -15);
// 	// printf("system -16: %x \n", -16);
// 	// ft_printf("mine -16: %x \n", -16);
// 	// printf("system -16: %x \n", -17);
// 	// ft_printf("mine -16: %x \n", -17);
// 	// printf("system -42: %x \n", -42);
// 	// ft_printf("mine -42: %x \n", -42);
// 	// printf("system -99: %x \n", -99);
// 	// ft_printf("mine -99: %x \n", -99);
// 	// printf("system -100: %x \n", -100);
// 	// ft_printf("mine -100: %x \n", -100);
// 	// printf("system -101: %x \n", -101);
// 	// ft_printf("mine -101: %x \n", -101);
// 	// printf(" %x ", INT_MAX);
// 	// printf(" %x ", INT_MIN);
// 	// printf(" %x ", LONG_MAX);
// 	// printf(" %x ", LONG_MIN);
// 	// printf(" %x ", UINT_MAX);
// 	// printf(" %x ", ULONG_MAX);
// }
