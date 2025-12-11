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
	size_t	bytes_count;

	buffer = malloc(BUFFER_SIZE + 1) * sizeof(char);
	if (!buffer)
		return (NULL);
	bytes_count = 1;
	while (!ft_strchr(box, '\n'))
	{
	}
	return (box);
}

char	*output_line(char *box)
{
	int		bytes;
	char	*line;

	if (!box || box[0] == NULL)
		return (NULL);
	bytes = 0;
	while (box[bytes] && box[bytes] != '\n')
		bytes++;
	if (box[bytes] = '\n')
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
	if (box[bytes] = '\n')
		line[bytes] = box[bytes];
	line[bytes + 1] = '\0';
	return (line);
}
char	*clean_box(char *box)
{
	int		i;
	int		j;
	char	*new_box;

	while (box[i] && box[i] != '\n')
		i++;
	if (box[i] == '\0')
	{
		free(box);
		return (NULL);
	}
	new_box = malloc((ft_strlen(box) - i + 1) * sizeof(char));
	if (!new_box)
		return (NULL);
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
	box = clean_box;
	return (line);
}