/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayan <rayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:23:59 by rayan             #+#    #+#             */
/*   Updated: 2025/12/16 18:52:06 by rayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *box)
{
	char	*buffer;
	size_t	bytes_count;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_count = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(box, '\n') && bytes_count != 0)
	{
		if (bytes_count == -1)
		{
			free(buffer);
			free(box);
			return (NULL);
		}
		buffer[bytes_count] = '\0';
		if (!box)
			box = ft_strjoin("", buffer);
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
	
}

char	*get_next_line(int fd)
{
	static char	*box;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	box = read_line(fd, box);
	if (!box)
		return (NULL);
	line = output_line(box);
	box = clean_box;
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("file_1.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }