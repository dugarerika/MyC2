/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:06:13 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/03 11:25:10 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	pdest = (char *) dest;
	psrc = (char *) src;
	while (n)
	{
		*pdest++ = *psrc++;
		n--;
	}
	return ((void *) dest);
}
