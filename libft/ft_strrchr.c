/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:57:19 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/03 09:51:51 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	length1(const char *s)
{
	int	k;

	k = 0 ;
	while (s[k] != '\0')
		k++;
	return (k - 1);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*ps;
	char	*bs;
	int		a;

	a = length1(s);
	ps = ((char *) s) + a;
	bs = ((char *) s) + a + 1;
	if (c == '\0')
		return (bs);
	if (c == 0)
		return ((char *)s);
	while (a >= 0)
	{
		if (*ps == (char) c)
		{
			return (ps);
		}
		ps--;
		a--;
	}
	return (NULL);
}
