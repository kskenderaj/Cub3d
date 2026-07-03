/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:15:42 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/11 18:19:50 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (0);
	if (src < dest)
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

// int	main()
// {
// 	char	ptr[] = "12345";
// 	//ptr[6] = '\0';
// 	char	i[] = "fives";
//     printf("%s\n", ptr);
// 	printf("%s\n", i);
//     printf("%s\n", (unsigned char *) ft_memmove(i, ptr, sizeof(i)));
// 	printf("%s\n", (unsigned char *) memmove(i, ptr, sizeof(i)));
//     //printf("%s\n", i);
// }