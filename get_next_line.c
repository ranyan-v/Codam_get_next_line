/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayan <rayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:23:59 by rayan             #+#    #+#             */
/*   Updated: 2025/12/11 20:16:54 by rayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *box)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while ((box == NULL || !ft_strchr(box, '\n')) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(box);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
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
	static char *box;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	box = read_line(fd, box);
	if (!box)
		return (NULL);
	line = output_line(box);
	box = clean_box(box);
	return (line);
}
