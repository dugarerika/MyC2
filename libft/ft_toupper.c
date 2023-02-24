/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:28:39 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/02 11:22:45 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int str)
{
	int	j;

	if (str >= 'a' && str <= 'z')
	{
		j = str - 32;
		str = j;
	}
	return (str);
}
