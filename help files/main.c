# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"

char	*get_next_line(int fd);

int	main(void)
{
	int	fd;
	char *line;
	int line_count = 1;
	
	fd = open("single_line_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		printf ("NULL\n");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
	   printf("[Line %d]: %s\n", line_count, line);
		free(line);
		line_count++;
	}
	if (line_count == 1)
		printf("NULL\n");
	else
		printf("End of file reached. Total lines read: %d\n", line_count - 1);
	close(fd);
	return (0);
}

int main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	fd1 = open("bonus_1.txt", O_RDONLY);
	fd2 = open("bonus_2.txt", O_RDONLY);

	if	(fd1 < 0 || fd2 < 0)
	{
		perror("open");
		return (1);
	}

	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);

		if (!line1 && !line2)
			break;
		if (line1)
		{
			printf("fd1: %s", line1);
			free(line1);
		}

		if (line2)
		{
			printf("fd2: %s", line2);
			free(line2);
		}
	}

	close(fd1);
	close(fd2);
	return (0);
}
