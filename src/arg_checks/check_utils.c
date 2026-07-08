/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:52:13 by mimacdou          #+#    #+#             */
/*   Updated: 2026/06/09 15:52:14 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../cub3d.h"

char	*cycle_gnl(int fd, char *to_search)
{
	char	*line;
	char	*tmp;
	int		flag;

	flag = 0;
	if (ft_strlen(to_search) == 1)
		flag = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (flag == 1)
			tmp = ft_strchr(line, (int)*to_search);
		else
			tmp = ft_strnstr(line, to_search, ft_strlen(line));
		if (!tmp)
			(free(line), line = get_next_line(fd));
		else
			return (line);
	}
	return (NULL);
}

bool	flood_status(int result)
{
	static bool	overview = false;

	if (result == 1)
		overview = true;
	return (overview);
}

int	store_house(int flag)
{
	static int	storage;

	if (flag < 999)
		storage = flag;
	return (storage);
}
