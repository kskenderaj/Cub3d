/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:45:56 by dgeorgiy          #+#    #+#             */
/*   Updated: 2026/02/23 20:35:21 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*last_add(char *buffer, char *str)
{
	char	*tmp;
	char	*line_to_be_returned;
	char	*pos_of_newline;

	pos_of_newline = ft_strchr(buffer, '\n');
	tmp = malloc((pos_of_newline - buffer + 2) * sizeof(char));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, buffer, pos_of_newline - buffer + 1);
	ft_strlcpy(buffer, pos_of_newline + 1, ft_strlen(pos_of_newline + 1) + 1);
	line_to_be_returned = ft_strjoin(str, tmp);
	return (free(tmp), free(str), line_to_be_returned);
}

static void	read_and_append(char *buffer, char **str)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buffer);
	free(*str);
	*str = tmp;
}

static char	*fill_buff(char *str, char *buffer, int fd)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read == BUFFER_SIZE)
	{
		if (!ft_strchr(buffer, '\n'))
			read_and_append(buffer, &str);
		else
			return (last_add(buffer, str));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	buffer[bytes_read] = '\0';
	if (ft_strchr(buffer, '\n'))
		return (last_add(buffer, str));
	tmp = ft_strjoin(str, buffer);
	free(str);
	str = tmp;
	ft_bzero(buffer, BUFFER_SIZE);
	if (ft_strlen(str) > 0)
		return (str);
	return (free(tmp), NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	char		*pos_of_newline;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	pos_of_newline = ft_strchr(buffer, '\n');
	if (pos_of_newline)
	{
		str = malloc((pos_of_newline - buffer + 2) * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, buffer, pos_of_newline - buffer + 1);
		if (*(pos_of_newline + 1) == '\0')
			ft_bzero(buffer, BUFFER_SIZE);
		else
			ft_strlcpy(buffer, pos_of_newline + 1, \
ft_strlen(pos_of_newline + 1));
		return (str);
	}
	str = ft_strdup(buffer);
	return (fill_buff(str, buffer, fd));
}
