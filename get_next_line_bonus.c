/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayan <rayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:49:43 by rayan             #+#    #+#             */
/*   Updated: 2026/02/07 16:58:48 by rayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(int fd, char *box)
{
	char	*buffer;
	ssize_t	bytes_count;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_count = 1;
	while ((box == NULL || !ft_strchr(box, '\n')) && bytes_count != 0)
	{
		bytes_count = read(fd, buffer, BUFFER_SIZE);
		if (bytes_count < 0)
		{
			free(buffer);
			free(box);
			return (NULL);
		}
		buffer[bytes_count] = '\0';
		if (!box)
			box = ft_strdup(buffer);
		else
			box = ft_strjoin(box, buffer);
	}
	free(buffer);
	return (box);
}

char	*output_line(char *box)
{
	int		bytes;
	char	*line;

	if (!box || box[0] == '\0')
		return (NULL);
	bytes = 0;
	while (box[bytes] && box[bytes] != '\n')
		bytes++;
	if (box[bytes] == '\n')
		bytes++;
	line = malloc((bytes + 1) * sizeof(char));
	if (!line)
		return (NULL);
	bytes = 0;
	while (box[bytes] && box[bytes] != '\n')
	{
		line[bytes] = box[bytes];
		bytes++;
	}
	if (box[bytes] == '\n')
		line[bytes++] = '\n';
	line[bytes] = '\0';
	return (line);
}

char	*clean_box(char *box)
{
	int		i;
	char	*new_box;

	i = 0;
	while (box[i] && box[i] != '\n')
		i++;
	if (box[i] == '\0')
	{
		free(box);
		return (NULL);
	}
	new_box = ft_substr(box, i + 1, ft_strlen(box) - (i + 1));
	free(box);
	return (new_box);
}

char	*get_next_line(int fd)
{
	static char	*box[MAX_FD];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	temp = read_line(fd, box[fd]);
	if (!temp)
	{
		box[fd] = NULL;
		return (NULL);
	}
	box[fd] = temp;
	line = output_line(box[fd]);
	box[fd] = clean_box(box[fd]);
	return (line);
}
