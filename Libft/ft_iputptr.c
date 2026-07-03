/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:01:14 by mimacdou          #+#    #+#             */
/*   Updated: 2025/03/27 16:01:15 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iputptr(size_t argp)
{
	int				count;

	count = 0;
	if (!argp)
	{
		count += ft_iputstr("(nil)");
		return (count);
	}
	count += ft_iputstr("0x");
	count += ft_iputnum_ptr(argp);
	return (count);
}
