/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:33:54 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/11 18:30:00 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	uc;
	char			*p;

	uc = (unsigned char) c;
	p = (char *) s;
	i = 0;
	if (c == '\0')
		return (p + ft_strlen(p));
	while (p[i] != '\0')
	{
		if (p[i] == uc)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
