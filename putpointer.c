/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:46:37 by erikadugar        #+#    #+#             */
/*   Updated: 2023/03/13 08:31:44 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return ((void *) p);
	while (i < count * size)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}

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

static int	h_digits(unsigned long long n)
{
	int	digits;

	digits = 2;
	if (n == 0)
		return (3);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits) ;
}

void	ptr(unsigned long long d, char *acum)
{
   char	mod;
	int		i;

	i = 0;
  	acum = ft_calloc(h_digits(d), 1);
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
		free(acum);
}

int	putpointer(unsigned long long d)
{
	char	*acum;

   acum = NULL;
   acum = ft_calloc(h_digits(d), 1);
   if (d == 0)
	{
		write(1, "0x", 2);
		putunsigned(0, 1);
	}
	else
   {
		write(1, "0x", 2);
		ptr(d, acum);
   }
	free(acum);
	return (h_digits(d));
}
