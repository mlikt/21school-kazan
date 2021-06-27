#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFFER_SIZE 256

char	*gnl_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strlen(const char *s);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ptrchr(char *c, char a);
#endif