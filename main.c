#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

/*
void	print_next_line(int fd)
{
	char	*line;
	int	i = 1;

	line = get_next_line(fd);
	while (line)
	{
		printf("\n[line %d]\n%s\n----------\n", i, line);
		if (line)
			free(line);
		line = get_next_line(fd);
		i++;
		if (line)
			printf("\n[line %d]\n%s\n----------\n", i, line);
		if (line)
			free(line);
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
#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	char	*line = NULL;
	int	fd = open(av[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}*/

int	main(int ac, char **av)
{
	(void)ac;
	char	*line = NULL;
	// (void)av;
	// int	fd = -1;/*open(av[1], O_RDONLY);*/
	int	fd = open(av[1], O_RDONLY);
	printf("1 -> %s\n", line = get_next_line(fd));
	free(line);
	printf("2 -> %s\n", line = get_next_line(fd));
	free(line);
	close(fd);
	printf("3 -> %s\n", line = get_next_line(-1));
	free(line);
	fd = open(av[1], O_RDONLY);
	printf("4 -> %s\n", line = get_next_line(fd));
	free(line);
	printf("5 -> %s\n", line = get_next_line(fd));
	free(line);
	printf("6 -> %s\n", line = get_next_line(fd));
	free(line);
	printf("7 -> %s\n", line = get_next_line(fd));
	free(line);
	printf("8 -> %s\n", line = get_next_line(fd));
	free(line);
}
