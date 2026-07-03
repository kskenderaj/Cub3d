/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:15:14 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/11 18:35:01 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	size_t			i;
	size_t			j;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (n <= dest_len)
		return (src_len + n);
	j = dest_len;
	while (src[i] != '\0' && i < n - dest_len - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j + i] = '\0';
	return (dest_len + src_len);
}
