/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:24:07 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/11 18:12:44 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uno;
	unsigned char	*dos;
	size_t			i;

	uno = (unsigned char *)s1;
	dos = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (uno[i] != dos[i])
			return (uno[i] - dos[i]);
		i++;
	}
	return (0);
}
