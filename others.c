/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:45:05 by etavera-          #+#    #+#             */
/*   Updated: 2023/03/07 11:55:41 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// void	ft_str_is_character(char str)
// {
// 	int	result;

// 	result = 1;
// 		if (str >= '0' && str <= '9')
// 		{
// 			putnbr_fd((int)str, 1);
// 		}
// 		else
// 		{
// 			write(1, &str, 1);
// 		}
// }



// void	ft_atoi(char *str)
// {
// 	int	neg;
// 	int	result;
// 	int	k;

// 	k = 0;
// 	neg = 1;
// 	result = 0;
// 	while (str[k] == 32 || (str[k] >= 9 && str[k] <= 13))
// 	{
// 		k++;
// 	}
// 	if (str[k] == 45 || str[k] == 43)
// 	{
// 		if (str[k] == 45)
// 		{
// 			neg = neg * -1;
// 		}
// 	k++;
// 	}
// 	while (str[k] <= 57 && str[k] >= 48)
// 	{
// 		result = (result * 10) + (str[k] - 48);
// 		k++;
// 	}
// 	result = result * neg;
// 	ft_putnbr(result);

// }

// void	put_oct(int d)
// {
// 	int	i;
// 	int	octal;

// 	i = 1;
// 	octal = 0;
// 	while (d)
// 	{
// 		octal += (d % 8) * i;
// 		d /= 8;
// 		i *= 10;
// 	}
// 	putnbr(octal, 1);
// }
