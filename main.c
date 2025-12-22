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
	
	fd = open("long.txt", O_RDONLY);
	if (fd < 0)
	{
	    perror("open failed");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
        printf("Line %d: [%s]\n", line_count, line);
		free(line);
		line_count++;
	}
	printf("End of file reached. Total lines read: %d\n", line_count - 1);
    close(fd);
	return (0);
}