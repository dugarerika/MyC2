/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikadugar <erikadugar@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:03:09 by etavera-          #+#    #+#             */
/*   Updated: 2023/03/12 22:37:43 by erikadugar       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf(const char *fstr, ...);
int	ft_putstr(char const *str);
int	putnbr(int a, int fd);
int	putstr(char const *str);
int	puthex(unsigned int d, char base);
int	putunsigned(unsigned int a, int fd);
int	ft_strlen(const char *str);
int putpointer(unsigned long long d);
#endif
