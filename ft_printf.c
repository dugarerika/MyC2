/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:12:39 by etavera-          #+#    #+#             */
/*   Updated: 2023/03/09 15:23:49 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_bzero(void *str, unsigned int n)
{
	unsigned int	i;
	unsigned char	*p;

	p = str;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

int	ft_strlen(const char *str)
{
	int	r;

	r = 0;
	while (str[r] != '\0')
	{
		r++;
	}
	return (r);
}

int	putstr(char const *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str)));
}

size_t	i_digits(int n)
{
	size_t	digits;

	digits = 0;
	if (n <= 0)
		digits += 1;
	while (n != 0)
	{
		n /= 10;
		digits += 1;
	}
	return (digits);
}

int	putnbr(int a, int fd)
{
	int	c;

	if (a == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		putnbr(147483648, fd);
	}
	else if (a < 0)
	{
		write(fd, "-", 1);
		putnbr(-a, fd);
	}
	else if (a >= 0 && a <= 9)
	{
		c = a + '0';
		write(fd, &c, 1);
	}
	else
	{
		c = (a % 10) + '0';
		putnbr(a / 10, fd);
		write(fd, &c, 1);
	}
	return (i_digits(a));
}


size_t	i_digitsun(unsigned int n)
{
	size_t	digits;

	digits = 0;
	if (n <= 0)
		digits += 1;
	while (n != 0)
	{
		n /= 10;
		digits += 1;
	}
	return (digits);
}

int	putunsigned(unsigned int a, int fd)
{
	int	c;

	if (a == 2147483648)
	{
		write(fd, "2", 1);
		putunsigned(147483648, fd);
	}
	else if (a < 0)
	{
		write(fd, "-", 1);
		putunsigned(-a, fd);
	}
	else if (a >= 0 && a <= 9)
	{
		c = a + '0';
		write(fd, &c, 1);
	}
	else
	{
		c = (a % 10) + '0';
		putunsigned(a / 10, fd);
		write(fd, &c, 1);
	}
	return (i_digitsun(a));
}


char	*rev(char *tab)
{
	int	i;
	int	t;
	int size;

	size = ft_strlen(tab);
	i = 0;
	while (i < size / 2)
	{
		t = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = t;
	i++;
	}
	return (tab);
}

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

	i = 0;
	acum = malloc(h_digits(d));

	if (d == 0)
		putunsigned(d, 1);
	else
	{
		while (d > 0 && acum[i] != '\0')
		{
			mod = d % 16;
			if (mod <= 15 && mod >= 10)
			{
				if (base == 'X')
					mod = mod + 55;
				else if (base == 'x')
					mod = mod + 87;
				acum[i] = mod;
				i++;
			}
			else if (mod <= 9)
			{
				mod = mod + 48;
				acum[i] = mod;
				i++;
			}
			d = d / 16;
		}
		putstr(rev(acum));
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

int	main(void)
{
	printf("system -42: %x \n", -42);
	ft_printf("mine -42: %x \n", -42);
	printf("system 42: %x \n", 42);
	ft_printf("mine 42: %x \n", 42);
	printf("system 0: %x \n", 0);
	ft_printf("mine 0: %x \n", 0);
	printf("system 1: %x \n", 1);
	ft_printf("mine 1: %x \n", 1);

// printf("system: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// ft_printf("mine  : %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// printf("system: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\n", 'A', "42", 42, 42 ,42 , 42, 42);
// ft_printf("mine  : %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\n", 'A', "42", 42, 42 ,42 , 42, 42);
// printf("system: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// ft_printf("mine  : %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// printf("system 0: %x \n", 0);
	// ft_printf("mine 0: %x \n", 0);
	// printf("system 1: %x \n", 1);
	// ft_printf("mine 1: %x \n", 1);
	// printf("system 9: %x \n", 9);
	// ft_printf("mine 9: %x \n", 9);
	// printf("system 10: %x \n", 10);
	// ft_printf("mine 10: %x \n", 10);
	// printf("system 11: %x \n", 11);
	// ft_printf("mine 11: %x \n", 11);
	// printf("system 15: %x \n", 15);
	// ft_printf("mine 15: %x \n", 15);
	// printf("system 16: %x \n", 16);
	// ft_printf("mine 16: %x \n", 16);
	// printf("system 17: %x \n", 17);
	// ft_printf("mine 17:  %x \n", 17);
	// printf("system 42: %x \n", 42);
	// ft_printf("mine 42: %x \n", 42);
	// printf("system 99: %x \n", 99);
	// ft_printf("mine 99:  %x \n", 99);
	// printf("system 100: %x \n", 100);
	// ft_printf("mine 100: %x \n", 100);
	// printf("system 101: %x \n", 101);
	// ft_printf("mine 101: %x \n", 101);
	// printf("system -1: %x \n", -1);
	// ft_printf("mine -1: %x \n", -1);
	// printf("system -2: %x \n", -2);
	// ft_printf("mine -2: %x \n", -2);
	// printf("system -1: %x \n", -3);
	// ft_printf("mine -1: %x \n", -3);
	// printf("system -1: %x \n", -4);
	// ft_printf("mine -1: %x \n", -4);
	// printf("system -1: %x \n", -5);
	// ft_printf("mine -1: %x \n", -5);
	// printf("system -9: %x \n", -9);
	// ft_printf("mine -9: %x \n", -9);
	// printf("system -10: %x \n", -10);
	// ft_printf("mine -10: %x \n", -10);
	// printf("system -11: %x \n", -11);
	// ft_printf("mine -11: %x \n", -11);
	// printf("system -14: %x \n", -14);
	// ft_printf("mine -14: %x \n", -14);
	// printf("system -15: %x \n", -15);
	// ft_printf("mine -15: %x \n", -15);
	// printf("system -16: %x \n", -16);
	// ft_printf("mine -16: %x \n", -16);
	// printf("system -16: %x \n", -17);
	// ft_printf("mine -16: %x \n", -17);
	// printf("system -42: %x \n", -42);
	// ft_printf("mine -42: %x \n", -42);
	// printf("system -99: %x \n", -99);
	// ft_printf("mine -99: %x \n", -99);
	// printf("system -100: %x \n", -100);
	// ft_printf("mine -100: %x \n", -100);
	// printf("system -101: %x \n", -101);
	// ft_printf("mine -101: %x \n", -101);
	// printf(" %x ", INT_MAX);
	// printf(" %x ", INT_MIN);
	// printf(" %x ", LONG_MAX);
	// printf(" %x ", LONG_MIN);
	// printf(" %x ", UINT_MAX);
	// printf(" %x ", ULONG_MAX);
}
