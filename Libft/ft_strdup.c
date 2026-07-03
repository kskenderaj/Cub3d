/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:34:48 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/11 18:31:16 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sd;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	sd = (char *)malloc(sizeof(char) * (size + 1));
	while (s[i])
	{
		sd[i] = s[i];
		i++;
	}
	sd[i] = '\0';
	return (sd);
}
