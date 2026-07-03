/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:59:23 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/11 18:05:28 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_dig(int n)
{
	int	count;

	count = 1;
	while (n)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

static void	itoa_rec(long int n, char *s)
{
	char	i;
	int		j;

	if (n < 0)
	{
		*s++ = '-';
		itoa_rec(-n, s);
		return ;
	}
	if (n == 0)
	{
		*s++ = '0';
		return ;
	}
	i = (n % 10) + 48;
	itoa_rec(n / 10, s);
	j = count_dig(n / 10) - 1;
	while (j--)
	{
		s++;
	}
	*s++ = i;
	*s = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		nchar;

	neg = 0;
	if (n < 0)
		neg = 1;
	nchar = count_dig(n) + neg;
	if (n == 0)
		nchar += 1;
	if (nchar)
	{
		str = (char *)ft_calloc((nchar), sizeof(char));
		if (str)
			itoa_rec((long int)n, str);
	}
	else
		return (NULL);
	return (str);
}
