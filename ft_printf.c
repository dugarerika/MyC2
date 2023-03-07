/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikadugar <erikadugar@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:12:39 by etavera-          #+#    #+#             */
/*   Updated: 2023/03/07 09:04:48 by erikadugar       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


static size_t	i_digits(int n)
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

int	putunsigned(unsigned int a)
{
	int	c;

	if (a < 0)
	{
		write(1, "-", 1);
		putunsigned(-a);
	}
	else if (a >= 0 && a <= 9)
	{
		c = a + '0';
		write(1, &c, 1);
	}
	else
	{
		c = (a % 10) + '0';
		putunsigned(a / 10);
		write(1, &c, 1);
	}
	return (i_digits(a));
}

int	putnbr_fd(int a, int fd)
{
	int	c;

	if (a == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		putnbr_fd(147483648, fd);
	}
	else if (a < 0)
	{
		write(fd, "-", 1);
		putnbr_fd(-a, fd);
	}
	else if (a >= 0 && a <= 9)
	{
		c = a + '0';
		write(fd, &c, 1);
	}
	else
	{
		c = (a % 10) + '0';
		putnbr_fd(a / 10, fd);
		write(fd, &c, 1);
	}
	return (i_digits(a));
}

void	hex(unsigned int d, char base)
{
	char	mod;
	char	*acum;
	int i;
	int	r;

	i = -1;
	r = d;
	acum = NULL;
	while (r != 0)
	{
		r = r / 16;
		i++;
	}
	acum = malloc(i);
	if(d == 0)
		putnbr_fd(0,1);
	while (d > 0)
	{

		mod = d % 16;
		if (mod <= 15 && mod >= 10)
		{
			if (base == 'X')
			{
				write(1, "0X", 1);
				mod = mod + 55;
			}
				
			else if (base == 'x')
						{
				write(1, "0x", 1);
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
	free(acum);
}

int	put_hex(unsigned int d, char base)
{

	hex(d, base);
	return (d);
}

void	put_oct(int d)
{
	int	i;
	int	octal;

	i = 1;
	octal = 0;

	while (d)
	{
		octal += (d % 8) * i;
		d /= 8;
		i *=10;
	}
	putnbr_fd(octal, 1);
}

void	ft_str_is_character(char str)
{
	int	result;

	result = 1;
		if (str >= '0' && str <= '9')
		{
			putnbr_fd((int)str, 1);
		}
		else
		{
			write(1, &str, 1);
		}
}



// void	ft_atoi(char *str)
// {
// 	int	neg;
// 	int	result;
// 	int	k;

// 	k = 0;
// 	neg = 1;
// 	result = 0;
// 	while (str[k] == 32 || (str[k] >= 9 && str[k] <= 13))
// 	{
// 		k++;
// 	}
// 	if (str[k] == 45 || str[k] == 43)
// 	{
// 		if (str[k] == 45)
// 		{
// 			neg = neg * -1;
// 		}
// 	k++;
// 	}
// 	while (str[k] <= 57 && str[k] >= 48)
// 	{
// 		result = (result * 10) + (str[k] - 48);
// 		k++;
// 	}
// 	result = result * neg;
// 	ft_putnbr(result);

// }

int	ft_check_specifier(const char spcr, va_list ptr)
{
	char c;
	if (spcr == 'i' || spcr == 'd')
		return (putnbr_fd(va_arg(ptr, int), 1));
	else if (spcr == 'c')
	{
		c = va_arg(ptr, int);
		return (write(1, &c,1));
	}
	else if (spcr == 's')
		return (putstr(va_arg(ptr, char *)));
	else if (spcr == 'p')
		write(1, "pointer address", 11);
	else if (spcr == 'u')
		return (putunsigned(va_arg(ptr, unsigned int)));
	else if (spcr == 'x' || spcr == 'X')
		return (put_hex(va_arg(ptr, unsigned int), spcr));
	else if (spcr == '%')
		return (write (1, "%", 1));
	return (0);
}

int ft_printf(const char *fstr, ...)
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
// 	hex(90, 'X');
// }
