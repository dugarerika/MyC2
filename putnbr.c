/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:49:02 by etavera-          #+#    #+#             */
/*   Updated: 2023/03/07 11:54:25 by etavera-         ###   ########.fr       */
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
