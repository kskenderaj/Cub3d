/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:51:20 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/11 18:15:07 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

// int	main()
// {
// 	char	ptr[] = "Hello";
// 	//ptr[15] = '\0';
// 	char	i[] = "fives";
//     printf("%s\n", ptr);
// 	printf("%s\n", i);
// 	//ft_memcpy(i, ptr, 5);
//     printf("%s\n", (unsigned char *) memcpy(i, ptr, 5));
//     //printf("%s\n", ptr);
// 	//printf("%s\n", i);
// }