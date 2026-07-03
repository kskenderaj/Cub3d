/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:56:34 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/11 18:40:25 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	char			*p;
	int				i;

	uc = (unsigned char) c;
	p = (char *)s;
	i = ft_strlen(p);
	if (c == '\0')
		return (p + ft_strlen(p));
	while (i != 0)
	{
		i--;
		if (p[i] == uc)
			return (&p[i]);
	}
	return (NULL);
}
