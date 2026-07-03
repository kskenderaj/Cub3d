/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:09:40 by mimacdou          #+#    #+#             */
/*   Updated: 2024/11/30 17:35:03 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*int     main()
{
	int    c = 'h';
	int    j = '5';
	printf("%d \n", isalpha(c));
	printf("%d \n", isalpha(j));
	printf("%d \n", ft_isalpha(c));
	printf("%d \n", ft_isalpha(j));
}*/
