/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:19:14 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/11 18:40:45 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	int		n;

	i = 1;
	start = 0;
	end = 0;
	n = ft_strlen(s1);
	while (i <= n)
	{
		if (!ft_strchr(set, s1[i - 1]) && !start)
			start = i;
		if (!ft_strchr(set, s1[n - i]) && !end)
			end = n - i + 1;
		i++;
	}
	if (start && end)
		return (ft_substr(s1, start - 1, end - start + 1));
	return (ft_substr(s1, 0, 0));
}
