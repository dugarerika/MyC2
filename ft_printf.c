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

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ((void) 0);
	while (str[i] != '\0' && str != NULL)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int a)
{
	int	c;

	if (a == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr(147483648);
	}
	else if (a < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-a);
	}
	else if (a >= 0 && a <= 9)
	{
		c = a + '0';
		write(1, &c, 1);
	}
	else
	{
		c = (a % 10) + '0';
		ft_putnbr(a / 10);
		write(1, &c, 1);
	}
}

void put_hex_neg(int d)
{

}

void	put_hex(int d, char base)
{
	char	mod;
	char	*acum;
	int	i;
	int	r;

	i = -1;
	r = d;
	while (r != 0)
	{
		r = r / 16;
		i++;
	}
	acum = malloc(i);
	if(d == 0)
		ft_putnbr(0);
	if (d < 0)
		put_hex_neg(d);
	while (d != 0)
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
	ft_putstr(acum);
	free(acum);
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
	ft_putnbr(octal);
}

void	ft_str_is_character(char str)
{
	int	result;

	result = 1;
		if (str >= '0' && str <= '9')
		{
			ft_putnbr((int)str);
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

void	ft_check_specifier(const char spcr, va_list ptr)
{
	if (spcr == 'i' || spcr == 'd')
		ft_putnbr(va_arg(ptr, int));
	if (spcr == 'c')
		ft_str_is_character((char)va_arg(ptr, int));
	if (spcr == 's')
		ft_putstr(va_arg(ptr, char *));
	if (spcr == 'p')
		write(1, "pointer address", 11);
	if (spcr == 'f')
		write(1, "floating", 8);
	if (spcr == 'o')
		put_oct(va_arg(ptr, int));
	if (spcr == 'u')
		ft_putnbr(va_arg(ptr, int));
	if (spcr == 'x' || spcr == 'X')
		put_hex(va_arg(ptr, int), spcr);
	if (spcr == '%')
		write (1, "%", 1);
	else
		return ((void)0);
}

int ft_printf(const char *fstr, ...)
{
	va_list	ptr;
	int		i;
	int		j;

	va_start(ptr, fstr);
	i = 0;
	j = 0;
	while (fstr[i])
	{
		if (fstr[i] == '%')
		{
			ft_check_specifier(fstr[i + 1], ptr);
			i++;
		}
		else if (fstr[i] == '\n')
			write(1, "\n", 1);
		else
			write(1, &fstr[i], 1);
		i++;
	}
	va_end(ptr);
	return (0);

}

int	main(void)
{
	char str[] = " -+++++-01234ab567";
	// printf ("Integers: %u %i \n", -3456, 3456);
	// ft_printf ("Integers: %u %i \n", -3456, 3456);
	// printf ("Characters: %c %c \n", "z", 80);
    // ft_printf ("Characters: %c %c \n", "z", 80) //need to check this scenario;
	printf ("Octal value is : %o \n", 2567);
	ft_printf ("Octal value is : %o \n", 2567);
	ft_printf ("Characters: %c \n", 'z');
	ft_printf ("Characters: %c \n", 80);
	// printf ("Decimals: %d %ld\n", 1997, 32000L);
	// printf ("floats: %4.2f %+.0e %E \n", 3.14159, 3.14159, 3.14159);
	// printf ("Preceding with empty spaces: %10d \n", 1997);
	// printf ("Preceding with zeros: %010d \n", 1997);
	printf ("Preceding with zeros: %i \n", 1997);
	ft_printf ("Preceding with zeros: %i \n", 1997);
	ft_printf ("Preceding with zeros: %d \n", 1997);
	ft_printf ("Preceding with zeros: %s %d \n", "abc", 12);
	ft_printf ("%d %d \n", 1997, 12);
	// printf ("Width: %*d \n", 15, 140);
	// ft_printf ("Width: %*d \n", 15, 140);
	printf("%i\n", 0);
	ft_printf("%i\n", 0);
	printf("%i\n", -1);
	ft_printf("%i\n", -1);
	printf("%i\n", 0);
	ft_printf("%x\n", 0);
	printf("%x\n", 100);
	ft_printf("%x\n", 100);
		printf("%x\n", 1);
	ft_printf("%x\n", 1);
	printf("%x\n", -1);
	ft_printf("%x\n", -1);
	printf("%x\n", 9);
	ft_printf("%x\n", 9);
	printf("%x\n", 2147483647);
	ft_printf("%x\n", 2147483647);
	printf("%x\n", 32768);
	ft_printf("%x\n", 32768);

	//printf("%x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("%%|\n");
	printf("%%|\n");
	ft_printf("%#8x|\n", 234567);
	printf("%#8x|\n", 234567);
	ft_printf ("%s \n", "Educative");
	printf("%x %x %x %x %x %x %x %x\n", 0xC0, 0xC0, 0x61, 0x62, 0x63, 0x31, 0x32, 0x33);
	ft_printf("%x %x %x %x %x %x %x %x\n", 0xC0, 0xC0, 0x61, 0x62, 0x63, 0x31, 0x32, 0x33);
	printf("%X %X %X %X %X %X %X %X\n", 0xC0, 0xC0, 0x61, 0x62, 0x63, 0x31, 0x32, 0x33);
	ft_printf("%X %X %X %X %X %X %X %X\n", 0xC0, 0xC0, 0x61, 0x62, 0x63, 0x31, 0x32, 0x33);
	printf("%d", atoi(str));
}
