/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:42:54 by juliatav          #+#    #+#             */
/*   Updated: 2025/11/13 13:38:40 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_buffers(char *b1, char *b2)
{
	free(b1);
	free(b2);
	return (NULL);
}

ssize_t	find_newline(char *s)
{
	ssize_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_file(char *stash, int fd)
{
	char	*buffer;
	char	*temp;
	ssize_t	b_read;

	b_read = 1;
	buffer = ft_calloc(1, (size_t)(BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (free_buffers(buffer, stash));
		buffer[b_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		if (!temp)
			return (free_buffers(buffer, stash));
		free(stash);
		stash = temp;
		if (find_newline(stash) != -1)
			break ;
	}
	free(buffer);
	return (stash);
}

char	*extract_line(char **stash)
{
	ssize_t	line_index;
	char	*leftover;
	char	*line;

	leftover = NULL;
	if (!(**stash) || !(*stash))
		return (NULL);
	line_index = find_newline(*stash);
	if (line_index == -1)
		line = ft_strdup(*stash);
	else
	{
		line = ft_substr(*stash, 0, line_index + 1);
		leftover = ft_substr(*stash, line_index + 1, ft_strlen(*stash));
	}
	free(*stash);
	*stash = leftover;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(stash, fd);
	if (!stash || !(*stash))
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(&stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (line);
}
