/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:12:05 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/03 11:26:46 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_length1(char *s)
{
	size_t	k;

	k = 0 ;
	while (s[k] != '\0')
		k++;
	return (k);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	psize;
	size_t	lsrc;
	char	*psrc;

	psrc = (char *)src;
	lsrc = ft_length1(psrc);
	psize = 0;
	if (dstsize == 0)
		return (ft_length1(psrc));
	while (dstsize > 0 && *dst)
	{
		dst++;
		dstsize--;
		psize++;
	}
	while (dstsize > 1 && *psrc)
	{
		*dst++ = *psrc++;
		dstsize--;
	}
	if (dstsize >= 1)
		*dst = '\0';
	if (dstsize == 0 && dst == 0)
		return (lsrc);
	return (psize + lsrc);
}
