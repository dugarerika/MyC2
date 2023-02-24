/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:13:52 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/03 13:05:14 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	result;
	int	k;

	k = 0;
	neg = 1;
	result = 0;
	while (str[k] == 32 || (str[k] >= 9 && str[k] <= 13))
	{
		k++;
	}
	if (str[k] == 45 || str[k] == 43)
	{
		if (str[k] == 45)
		{
			neg = neg * -1;
		}
	k++;
	}
	while (str[k] <= 57 && str[k] >= 48)
	{
		result = (result * 10) + (str[k] - 48);
		k++;
	}
	return (result * neg);
}
