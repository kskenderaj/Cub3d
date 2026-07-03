/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhidrob <shhidrob@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:22:21 by mimacdou          #+#    #+#             */
/*   Updated: 2026/03/06 23:04:00 by shhidrob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	bb;

	if (!s)
		return (NULL);
	bb = (unsigned char) c;
	while (n--)
		*(unsigned char *)s++ = bb;
	return (s);
}

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	unsigned char	i;
// 	unsigned char	*p;

// 	if (!s)
// 		return (NULL);
// 	p = (unsigned char *)s;
// 	i = (unsigned char)c;
// 	while (n--)
// 	{
// 		*p++ = i;
// 	}
// 	return (s);
// }

// int	main()git bra
// {
// 	char	ptr[] = "Hello me banana";
// 	ptr[15] = '\0';
// 	char	i = 'a';
// 	ft_memset(ptr, i, 5);
// 	printf("%s\n", ptr); 
// }
