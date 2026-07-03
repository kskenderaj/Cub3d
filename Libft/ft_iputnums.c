/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputnums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:14:27 by mimacdou          #+#    #+#             */
/*   Updated: 2025/03/20 16:15:07 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iputnums(long long n, int base, int caps)
{
	int		count;

	if (n < 0)
	{
		ft_iputchar('-');
		return (ft_iputnums(-n, base, caps) + 1);
	}
	if (n < base && !caps)
		return (ft_iputchar(BASE16[n]));
	else if (n < base && caps)
		return (ft_iputchar(ft_toupper(BASE16[n])));
	else
	{
		count = ft_iputnums(n / base, base, caps);
		return (count + ft_iputnums(n % base, base, caps));
	}
}
