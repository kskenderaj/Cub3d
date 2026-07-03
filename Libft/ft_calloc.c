/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhidrob <shhidrob@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:01:23 by mimacdou          #+#    #+#             */
/*   Updated: 2026/03/06 23:04:15 by shhidrob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*array;

	if (num == 0 || size == 0)
		return (malloc(0));
	if (num && SIZE_MAX / num < size)
		return (NULL);
	array = malloc(num * size);
	if (!array)
		return (NULL);
	ft_bzero(array, num * size);
	return (array);
}
