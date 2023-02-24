/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:50:10 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/02 11:18:00 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The isprint() function tests for any printing character, including space
(` ').  The value of the argument must be representable as an unsigned
char or the value of EOF.
*/

int	ft_isprint(int c)
{
	int	result;

	result = 1;
	if (c >= 32 && c <= 126)
	result = 1;
	else
	result = 0;
	return (result);
}
