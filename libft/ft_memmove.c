/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:39:54 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/03 14:19:05 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The memmove() function copies len bytes from string src to string dst.
     The two strings may overlap; the copy is always done in a non-destructive
     manner.
*/

void	*ft_memmove(void *dest, const void *src, size_t n )
{
	size_t			i;
	unsigned char	*pd;
	unsigned char	*ps;

	if (dest == NULL && src == NULL)
		return (NULL);
	pd = (unsigned char *) dest;
	ps = (unsigned char *) src;
	i = 0;
	if (src < dest)
	{
		while (n > 0)
		{
			pd[n - 1] = ps[n - 1];
			n--;
		}
		return (dest);
	}
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
	}
	return (dest);
}
