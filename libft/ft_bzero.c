/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:20:37 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/02 11:17:02 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
     The bzero() function writes n zeroed bytes to the string s.  If n is
     zero, bzero() does nothing.
*/

void	ft_bzero(void *str, unsigned int n)
{
	unsigned int	i;
	unsigned char	*p;

	p = str;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
