/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikadugar <erikadugar@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:46:37 by erikadugar        #+#    #+#             */
/*   Updated: 2023/03/12 22:17:56 by erikadugar       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*rev(char *tab)
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

static int	h_digits(unsigned int n)
{
	int	digits;

	digits = 2;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits) ;
}

void	ptr(unsigned long d, char *acum)
{
   char	mod;
	int		i;

	i = 0;

	while (d > 0)
		{
			mod = d % 16;
			if (mod <= 15 && mod >= 10)
			{
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

int	putpointer(unsigned long d)
{
	char	*acum;

   acum = NULL;
   acum = malloc(h_digits(d));
   if (d == 0)
		putunsigned(0, 1);
	else
   {
		write(1, "0x", 2);
		ptr(d, acum);
   }
	free(acum);
	return (h_digits(d));
}
