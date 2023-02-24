/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:30:45 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/02 11:15:00 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlenth(char *str)
{
	int	k;

	k = 0;
	while (str[k] != '\0')
		k++;
	return (k);
}

char	*ft_copy(char *cpy, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strdup(char *src)
{
	char	*str;

	str = (char *) malloc(ft_strlenth(src) + 1);
	if (str == NULL)
		return (0);
	ft_copy(str, src);
	return (str);
}
