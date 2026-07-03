/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:01:20 by mimacdou          #+#    #+#             */
/*   Updated: 2025/03/27 16:01:21 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iputstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (ft_iputstr("(null)"));
	while (*str)
		count += ft_iputchar(*str++);
	return (count);
}
