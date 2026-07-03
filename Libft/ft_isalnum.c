/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:22:49 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/11 17:56:43 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*int	main()
{
	int	i='p';
	int	g='P';
	int	j='1';
	int	h='?';
	printf("%d \n", isalnum(i));
	printf("%d \n", isalnum(g));
	printf("%d \n", isalnum(j));
	printf("%d \n", isalnum(h));
	printf("%d \n", ft_isalnum(i));
	printf("%d \n", ft_isalnum(g));
	printf("%d \n", ft_isalnum(j));
	printf("%d \n", ft_isalnum(h));
}*/
