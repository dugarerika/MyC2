/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:45 by etavera-          #+#    #+#             */
/*   Updated: 2023/02/02 11:14:24 by etavera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j > 0)
	{
		free(strs[j]);
		j--;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;
	int		size;
	int		j;

	i = 0;
	j = -1;
	str = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (++j < ft_count_word(s, c))
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		str[j] = ft_substr(s, i, size);
		if (!str[j])
		{
			ft_free(str, j);
			return (NULL);
		}
		i += size;
	}
	str[j] = 0;
	return (str);
}
