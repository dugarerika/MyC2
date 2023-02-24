/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:59:03 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/02 11:20:09 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int a, int fd)
{
	int	c;

	if (a == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		ft_putnbr_fd(147483648, fd);
	}
	else if (a < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-a, fd);
	}
	else if (a >= 0 && a <= 9)
	{
		c = a + '0';
		write(fd, &c, 1);
	}
	else
	{
		c = (a % 10) + '0';
		ft_putnbr_fd(a / 10, fd);
		write(fd, &c, 1);
	}
}
