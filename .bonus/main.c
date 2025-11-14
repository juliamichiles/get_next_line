#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


void	print_next_line(int fd)
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
int	main(int ac, char **av)
{
	int	fd;
	int	i = 1;

	while (i < ac)
	{
		printf("\n\n### FILE %d (%s) ###\n", i, av[i]);
		fd = open(av[i], O_RDONLY);
		print_next_line(fd);
		close(fd);
		i++;
	}
	return (0);
}
