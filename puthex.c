/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:48:08 by erikadugar        #+#    #+#             */
/*   Updated: 2023/03/13 06:17:40 by etavera-         ###   ########.fr       */
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

int	h_digits(unsigned int n)
{
	int	digits;

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

void	hex(unsigned int d, char base, char *acum)
{
   char	mod;
	int		i;

	i = 0;

	while (d > 0)
		{
			mod = d % 16;
			if (mod <= 15 && mod >= 10)
			{
				if (base == 'X')
					mod = mod + 55;
				else if (base == 'x'|| base == 'p')
					mod = mod + 87;
				acum[i++] = mod;
			}
			else if (mod <= 9)
			{
				mod = mod + 48;
				acum[i++] = mod;
			}
			d = d / 16;
		}
		putstr(rev(acum));
}

int	puthex(unsigned int d, char base)
{
	char	*acum;

   acum = NULL;
   acum = calloc(h_digits(d),1);
   if (d == 0)
		putunsigned(d, 1);
	else
		hex(d, base, acum);
	free(acum);
	if (base == 'p')
   	return (h_digits(d) + 6);
	else
		return (h_digits(d));
}

