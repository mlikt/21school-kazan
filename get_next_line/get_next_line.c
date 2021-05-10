#include "get_next_line.h"

char	*check_rem(char **rem, char **line)
{
	char	*tmp;

	*line = ft_substr("", 0, 1);
	tmp = NULL;
	if (*rem)
	{
		tmp = ptrchr(*rem, '\n');
		if (tmp)
		{
			*tmp = '\0';
			*line = ft_strjoin(*line, *rem);
			tmp++;
			ft_strlcpy(*rem, tmp, ft_strlen(tmp) + 1);
		}
		else
		{
			*line = ft_strjoin(*line, *rem);
			free(*rem);
			*rem = NULL;
		}
		return (tmp);
	}
	free(*rem);
	return (tmp);
}

int	free_if_error(char *buf, char **line)
{
	free(*line);
	*line = NULL;
	free(buf);
	return (-1);
}

void	get_rem(char **buf, char **rem, int read_chr, char **p_n)
{
	(*buf)[read_chr] = '\0';
	*p_n = ptrchr(*buf, '\n');
	if (*p_n)
	{	
		*(*p_n) = '\0';
		(*p_n)++;
		*rem = ft_substr(*p_n, 0, ft_strlen(*p_n));
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*rem[10239];
	char		*buf;
	int			read_chr;
	char		*p_n;

	if (fd < 0 || !line || !BUFFER_SIZE || BUFFER_SIZE < 1
		|| fd >= 10239)
		return (-1);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	read_chr = 1;
	p_n = check_rem(&rem[fd], line);
	while ((read_chr > 0) && !p_n)
	{
		read_chr = read(fd, buf, BUFFER_SIZE);
		if (read_chr == -1)
			return (free_if_error(buf, line));
		get_rem(&buf, &rem[fd], read_chr, &p_n);
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
	if (!read_chr)
		return (0);
	return (1);
}
