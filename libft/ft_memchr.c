/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:03:13 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/03 11:22:59 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
     The memchr() function locates the first occurrence of c
	 (converted to an unsigned char) in string s.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned char	*bs;

	ps = ((unsigned char *) s);
	bs = ((unsigned char *) s) + 1;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if (*ps == (unsigned char) c)
		{
			return ((void *)ps);
		}
		ps++;
	}
	if (c == '\0')
	{
		return ((void *)bs);
	}
	return (NULL);
}
