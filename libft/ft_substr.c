/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:22 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/02 11:22:38 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tr;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (0);
	i = (size_t) start;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	tr = (char *) malloc(len + 1);
	if (tr == NULL)
		return (0);
	j = 0;
	while (j < len && i < ft_strlen(s))
	{
		tr[j] = s[i];
		i++;
		j++;
	}
	tr[j] = '\0';
	return ((char *)tr);
}
