/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demolitron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:52:45 by mimacdou          #+#    #+#             */
/*   Updated: 2025/02/25 21:52:59 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_demolitron(const char *s, char c)
{
	char	*sd;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	size = ft_strlen(s);
	while (s[j++] != c)
		;
	sd = malloc((size - j) + 1);
	while (s[j])
	{
		sd[i] = s[j];
		i++;
		j++;
	}
	sd[i] = '\0';
	return (sd);
}
