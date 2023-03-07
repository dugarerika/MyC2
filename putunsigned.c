/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 06:49:11 by etavera-          #+#    #+#             */
/*   Updated: 2023/03/07 11:47:13 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	i_digits(unsigned int n)
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
	return (i_digits(a));
}
