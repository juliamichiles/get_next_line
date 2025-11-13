/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:42:45 by juliatav          #+#    #+#             */
/*   Updated: 2025/11/13 16:07:33 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef MAX_OPEN
#  define MAX_OPEN 65535
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# if BUFFER_SIZE > 9223372036854775806
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(size_t size, size_t nmemb);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);

ssize_t	find_newline(char *s);
char	*read_file(char *stash, int fd);
char	*extract_line(char **stash);
char	*get_next_line(int fd);

#endif
