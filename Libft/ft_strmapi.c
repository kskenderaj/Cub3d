/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:58:41 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/11 18:37:26 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			s_len;
	char			*mapi_str;
	char			n;

	i = 0;
	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	mapi_str = (char *)malloc(sizeof(char) * (s_len + 1));
	while (s[i] != '\0')
	{
		n = f(i, s[i]);
		mapi_str[i] = n;
		i++;
	}
	mapi_str[i] = '\0';
	return (mapi_str);
}
