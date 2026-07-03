/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:04:48 by mimacdou          #+#    #+#             */
/*   Updated: 2024/11/30 17:35:16 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int i)
{
	if ((i >= '0') && (i <= '9'))
		return (1);
	else
		return (0);
}

/*int	main()
{
	int	j = '0';
	int	g = 't';
	printf("%d \n", isdigit(j));
	printf("%d \n", isdigit(g));
	printf("%d \n", ft_isdigit(j));
	printf("%d \n", ft_isdigit(g));
}*/
