/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 06:27:06 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/02 11:18:52 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			k;
	unsigned char	*ps1;
	unsigned char	*ps2;

	k = 0;
	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	while (k < n)
	{
		if (ps1[k] != ps2[k])
		{
			return (ps1[k] - ps2[k]);
		}
		else if (ps1[k] == '\0' && ps2[k] == '\0')
		{
			return (0);
		}
		k++;
	}
	return (0);
}
