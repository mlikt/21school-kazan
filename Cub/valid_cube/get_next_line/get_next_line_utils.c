#include "../../header/get_next_line.h"

char	*ptrchr(char *c, char a)
{
	int	i;

	i = 0;
	while (*c != 0)
	{
		if (*c == a)
			return (c);
		c++;
	}
	return (0);
}

size_t	gnl_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
		count++;
	return (count);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 1;
	if (!dst && !src)
		return (0);
	if (dstsize == 0)
		return (gnl_strlen(src));
	if (gnl_strlen(src) != 0)
		n = (dstsize - 1);
	while (i < n && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (gnl_strlen(src));
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len;

	strjoin = (void *)0;
	len = gnl_strlen(s1) + gnl_strlen(s2);
	strjoin = (char *)malloc((len + 2) * sizeof(char));
	if (strjoin == (void *)0)
		return ((void *)0);
	gnl_strlcpy(strjoin, s1, gnl_strlen(s1) + 1);
	gnl_strlcpy(strjoin + gnl_strlen(s1), s2, len + 1);
	free((char *)s1);
	return (strjoin);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	substr = (void *)0;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == (void *)0)
		return (substr);
	gnl_strlcpy(substr, s + start, len + 1);
	return (substr);
}
