/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikadugar <erikadugar@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:48:08 by erikadugar        #+#    #+#             */
/*   Updated: 2023/03/11 14:56:29 by erikadugar       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

size_t	h_digits(unsigned int n)
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