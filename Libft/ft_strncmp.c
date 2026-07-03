/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:04:48 by mimacdou          #+#    #+#             */
/*   Updated: 2025/02/19 17:04:21 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	k;

	k = 0;
	while ((s1[k] != '\0' || s2[k] != '\0') && k < n)
	{
		if (s1[k] > s2[k])
			return (1);
		if (s1[k] < s2[k])
			return (-1);
		k++;
	}
	return (0);
}

/*
int	main(void)
{
	printf("%d\n", ft_strncmp("1234567890", "1234567890", 40));
}
*/
