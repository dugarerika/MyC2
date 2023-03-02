/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:12:39 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/24 09:27:35 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	r;

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

int	nbr(int a)
{
	int	c;
	c = 0;

	if (a == -2147483648)
	{
		return (write(1, "-", 1));
		return (write(1, "2", 1));
		nbr(147483648);
	}
	else if (a < 0)
	{
		return (write(1, "-", 1));
		nbr(a);
	}
	else if (a >= 0 && a <= 9)
	{
		c = a + '0';
		return (write(1, &c, 1));
	}
	else
	{
		c = (a % 10) + '0';
		nbr(a / 10);
		return (write(1, &c, 1));
	}
	return (c);
}

int	putnbr(int a)
{

	nbr(a);
	return (a);
}

void	hex(unsigned int d, char base)
{
	char	mod;
	char	*acum;
	int	i;
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
		nbr(0);
	while (d > 0)
	{
		
		mod = d % 16;
		if (mod <= 15 && mod >= 10)
		{
			if (base == 'X')
				mod = mod + 55;
			else if (base == 'x')
				mod = mod + 87;
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
	nbr(octal);
}

void	ft_str_is_character(char str)
{
	int	result;

	result = 1;
		if (str >= '0' && str <= '9')
		{
			nbr((int)str);
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
		return (nbr(va_arg(ptr, int)));
	else if (spcr == 'c')
	{
		c = va_arg(ptr, int);
		return (write(1, &c,1));
	}
	else if (spcr == 's')
		return(putstr(va_arg(ptr, char *)));
	else if (spcr == 'p')
		return (write(1, "pointer address", 11));
	else if (spcr == 'f')
		return (write(1, "floating", 8));
	else if (spcr == 'o')
		put_oct(va_arg(ptr, int));
	else if (spcr == 'u')
		return(nbr(va_arg(ptr, int)));
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
		// else if (fstr[i] == '\n')
		// 	j += write(1, "\n", 1);
		// else if (fstr[i] == 32)
		// 	j += write(1, " ", 1);
		else
			j += write(1, &fstr[i], 1);
		i++;
	}
	va_end(ptr);
	return (j);

}

int	main(void)
{
	printf(" %d ", -2147483647);
	ft_printf(" %d ", -2147483647);
}