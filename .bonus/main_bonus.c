#include "get_next_line_bonus.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void	close_files(int *files, int total)
{
	for (int i = 0; i < total; i++)
		close(files[i]);
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Number of arguments must be at least two\n");
		return 1;
	}

	int	files[100];
	int	total = ac - 1;
	int	i = 0;

	while (i < total)
	{
		files[i] = open(av[i + 1], O_RDONLY);
		if (files[i] < 0)
		{
			perror("open");
			return 1;
		}
		printf("Opened %s (fd=%d)\n", av[i + 1], files[i]);
		i++;
	}

	printf("\n--- Alternating reads ---\n");
	int finished_files = 0;

	while (finished_files < total)
	{
		finished_files = 0;
		for (int i = 0; i < total; i++)
		{
			char *line = get_next_line(files[i]);
			if (line)
			{
				printf("[%s] %s----------\n", av[i + 1], line);
				free(line);
			}
			else
			{
				printf("[%s] - nothing left to read\n", av[i + 1]);
				finished_files++;
			}
		}
	}
	close_files(files, total);
	return 0;
}
