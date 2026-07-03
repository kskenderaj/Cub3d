/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloured_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:31:57 by mimacdou          #+#    #+#             */
/*   Updated: 2026/02/23 20:34:46 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	coloured_write(const char *text, const char *colour_code, int flag)
{
	const char	*reset_code;

	reset_code = RESET_CODE;
	write(flag, colour_code, ft_strlen(colour_code));
	write(flag, text, ft_strlen(text));
	write(flag, reset_code, 4);
}
