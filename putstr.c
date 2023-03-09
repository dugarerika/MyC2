/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikadugar <erikadugar@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:58:13 by erikadugar        #+#    #+#             */
/*   Updated: 2023/03/09 06:24:16 by erikadugar       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	r;

	r = 0;
	while (str[r] != '\0')
	{
		r++;
	}
	return (r);
}

int	putstr(char const *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str)));
}
