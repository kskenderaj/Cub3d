/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:45:27 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/11 18:28:21 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**sentence;
	size_t	j;
	int		i;

	sentence = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!s || !sentence)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				j = ft_strlen(s);
			else
				j = ft_strchr(s, c) - s;
			sentence[i++] = ft_substr(s, 0, j);
			s += j;
		}
	}
	sentence[i] = NULL;
	return (sentence);
}
