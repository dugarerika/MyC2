/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:17:39 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/02 11:19:55 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int a, unsigned int n)
{
	unsigned int	i;
	unsigned char	*p;

	p = str;
	i = 0;
	while (i < n)
	{
		p[i] = a;
		i++;
	}
	return (str);
}
