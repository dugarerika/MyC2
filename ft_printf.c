/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:12:39 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/21 09:25:32 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <unistd.h>
# include  <stdlib.h> 



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

void	put_hex(int d)
{
	char	mod;
	char	*acum;
	int	i;
	int	r;

	r = d;
	while (r != 0)
	{
		r = r / 16;
		i++;
	}

	acum = malloc(i);

	while (d != 0)
	{
		mod = d % 16;
		if (mod <= 15 && mod >= 10)
		{
			mod = mod + 87;
			// write(1, &mod, 1);
			* acum ++ = 'A';
		}
		else if (mod <= 9)
		{
			mod = mod + 48;
			// write(1, &mod, 1);
			* acum ++ = 'b';
		}
		d = d / 16;
	}
	ft_putstr(acum);
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

void	ft_check_specifier(const char spcr, va_list ptr)
{
	if (spcr == 'i' || spcr == 'd')
		ft_putnbr(va_arg(ptr, int));
	if (spcr == 's')
		ft_putstr(va_arg(ptr, char *));
	if (spcr == 'p')
		write(1, "pointer address", 11);
	if (spcr == 'f')
		write(1, "floating", 8);
	if (spcr == 'o')
		write(1, "octal number", 12);
	if (spcr == 'u')
		write(1, "unsigned decimal", 16);
	if (spcr == 'x' || spcr == 'X')
		put_hex(va_arg(ptr, int));
	if (spcr == '%')
		write(1, "print a precent sign", 11);
	else
		return ((void)0);
}

void ft_printf(const char *fstr, ...)
{
	va_list	ptr;
	int num_var;
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
			// printf("info %s",va_arg(ptr, char));
			// write(1, &ptr, 1);
			i++;
		}
		else if (fstr[i] == '\n')
			write(1, "\n", 1);
		else
			write(1, &fstr[i], 1);
		i++;
	}
	va_end(ptr);
	// write(1, "(null)", 1);

}

int	main(void)
{
	// printf ("Integers: %i %u \n", -3456, 3456);
	// ft_printf ("Integers: %i %u \n", -3456, 3456);
	// printf ("Characters: %c %c \n", 'z', 80);
	// printf ("Decimals: %d %ld\n", 1997, 32000L);
	// printf ("floats: %4.2f %+.0e %E \n", 3.14159, 3.14159, 3.14159);
	// printf ("Preceding with empty spaces: %10d \n", 1997);
	// printf ("Preceding with zeros: %010d \n", 1997);
	ft_printf ("Preceding with zeros: %i \n", 1997);
	ft_printf ("Preceding with zeros: %d \n", 1997);
	ft_printf ("Preceding with zeros: %s %d \n ", "abc", 12);
	ft_printf ("%d %d \n ", 1997, 12);
	// printf ("Width: %*d \n", 15, 140);
	// ft_printf ("Width: %*d \n", 15, 140);
	ft_printf ("%s \n", "Educative");
	ft_printf("%x %x %x %x %x %x %x %x\n", 0xC0, 0xC0, 0x61, 0x62, 0x63, 0x31, 0x32, 0x33);

	return (0);
}