/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:20:27 by mimacdou          #+#    #+#             */
/*   Updated: 2025/01/11 18:33:24 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cabal;
	char	*nom;
	size_t	fleet;

	fleet = 0;
	if (s1)
		fleet += ft_strlen(s1);
	if (s2)
		fleet += ft_strlen(s2);
	cabal = (char *)malloc(sizeof(char) * (fleet + 1));
	if (!cabal)
		return (NULL);
	nom = cabal;
	while (*s1)
		*cabal++ = *s1++;
	while (*s2)
		*cabal++ = *s2++;
	*cabal = '\0';
	return (nom);
}
