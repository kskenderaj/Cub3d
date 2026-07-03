/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputnum_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:01:07 by mimacdou          #+#    #+#             */
/*   Updated: 2025/03/27 16:01:08 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iputnum_ptr(size_t n)
{
	size_t	base;
	int		count;

	base = 16;
	if (n < base)
		return (ft_iputchar(BASE16[n]));
	else
	{
		count = ft_iputnum_ptr(n / base);
		return (count + ft_iputnum_ptr(n % base));
	}
}
