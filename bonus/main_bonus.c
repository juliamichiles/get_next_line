#include "get_next_line_bonus.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


void	print_all_lines(int fd)
{
	char	*line;
	int	i = 1;

	line = get_next_line(fd);
	while (line)
	{
		printf("\n[line %d]\n%s\n----------\n", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

void	print_next_line(fd)
{
	char    *line;
	
	line = get_next_line(fd);
	if (line)
 		printf("%s\n----------\n", line);
	else
		printf("[NULL]\n");
}

void	close_files(int *fds, int size)
{
	int	i = 0;
	
	while (i < size)
		close(fds[i++]);
}
int	main(int ac, char **av)
{
	int	files[100];
	int	total = ac - 1;
	int	i = 0;

	while (i < ac)
	{
		files[i] = open(av[i + 1], O_RDONLY);
		if (files[i] < 0)
			return 1;
		printf("Opened %s (fd=%d)\n", av[i + 1], files[i]);
		i++;
	}

	printf("\n--- Alternating reads ---\n");
	
	int done = 0;
	while (!done)
	{
		for (int i = 0; i < total; i++)
		{
			char *line = get_next_line(files[i]);
			if (line)
			{
				printf("\n[%s] %s----------\n", av[i + 1], line);
				free(line);
				done = 0;
			}
		}
	}
	close_files(files, total);
	return (0);
}
