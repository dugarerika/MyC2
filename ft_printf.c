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

#include "printf.h"

void	ft_check_specifier(const char spcr, int c)
{
	if (spcr == 'i')
		write(1, "integer", 7);
	if (spcr == 'd')
		write(1, "decimal", 7);
	if (spcr == 's')
		write(1, "string of character", 19);
	if (spcr == 'p')
		write(1, "pointer address", 11);
	if (spcr == 'f')
		write(1, "floating", 8);
	if (spcr == 'o')
		write(1, "octal number", 12);
	if (spcr == 'u')
		write(1, "unsigned decimal", 16);
	if (spcr == 'x' || spcr == 'X')
		write(1, "number in hexadecimal", 21);
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
	num_var = ft_strlen(fstr);
	while (num_var)
	{
		if (fstr[i] == '%')
		{
			ft_check_specifier(fstr[i + 1], va_arg(ptr, int));
			// printf("info %s",va_arg(ptr, char));
			// write(1, &ptr, 1);
			num_var--;
		}
		else if (fstr[i] == '\n')
			write(1, "\n", 1);
		else
			write(1, &fstr[i], 1);
		num_var--;
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
	ft_printf ("Preceding with zeros: %i ", 1997);
	// printf ("Width: %*d \n", 15, 140);
	// ft_printf ("Width: %*d \n", 15, 140);
	// printf ("%s \n", "Educative");

	return (0);
}

	/*
	if (spcr == 'c') // Character
		write( 1, 1, 1);
	if (spcr == 'i' || spcr[i + 1] == 'd') // Signed INT
		write( 1, 1, 1);
	if (spcr == 'u') // Unsigned INT
		write( 1, 1, 1);
	if (spcr == 'o') // Unsigned Octal
		write( 1, 1, 1);
	if (spcr[i + 1] == 'x' || spcr[i + 1] == 'X') // unsigned Hexa
		write( 1, 1, 1);
	if (spcr[i + 1] == 'e' || spcr[i + 1] == 'E') // Floating point
		write( 1, 1, 1);
	if (spcr[i + 1] == 'g' || spcr[i + 1] == 'G') // Floating point
		write( 1, 1, 1);
	if (spcr[i + 1] == 'a' || spcr[i + 1] == 'A') // Floating point
		write( 1, 1, 1);
	if (spcr[i + 1] == 's') // String of Characters
		write( 1, 1, 1);
	if (spcr[i + 1] == 'p') // Pointer address
		write( 1, 1, 1);
	*/
	/*printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);*/
