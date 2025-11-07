#include "get_next_line.h"

void	*ft_calloc(size_t size, size_t nmemb)
{
	unsigned char	*block;
	size_t		total;
	size_t		i;
	
	i = 0;
	if (SIZE_MAX / size < nmemb)
		return (NULL);
	total = size * nmemb;
	if (total == 0)
		return(ft_strdup(""));
	block = malloc(total);
	if (!block)
		return (NULL);
	while (i < total)
		block[i++] = 0;
	return(block);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = ft_calloc(1, ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	while (*(str + i))
	{
		*(dup + i) = *(str + i);
		i++;
	}
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return(ft_strdup(s2));
	if (!s2)
		return(ft_strdup(s1));
	joined = ft_calloc(1, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	while (*s1)
		joined[i++] = *s1++;
	while (*s2)
		joined[i++] = *s2++;
	return (joined);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(0, 0));
	sub = ft_calloc(1, len + 1);
	if (!sub)
		return (NULL);
	while (i < len && s[start])
		sub[i++] = s[start++];
	return (sub);
}
