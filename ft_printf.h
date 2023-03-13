/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:03:09 by etavera-          #+#    #+#             */
/*   Updated: 2023/03/13 12:28:35 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf(const char *fstr, ...);
int	ft_putstr(const char *str);
int	putnbr(int a, int fd);
int	putstr(const char *str);
int	puthex(unsigned int d, char base);
int	putunsigned(unsigned int a, int fd);
int	ft_strlen(const char *str);
int	putpointer(unsigned long long d);
#endif
