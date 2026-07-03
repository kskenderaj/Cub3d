/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reducition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:54:49 by mimacdou          #+#    #+#             */
/*   Updated: 2025/02/25 21:55:35 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reductitron(const char *s, char c)
{
	char	*sd;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	size = 0;
	while (s[size++] != c)
		;
	sd = malloc(size);
	while (i <= size - 2)
	{
		sd[i] = s[i];
		i++;
	}
	sd[i] = '\0';
	return (sd);
}
