//
// Created by Aleksey Tvorogov on 26.11.2021.
//
#include "get_next_line.h"

char	*check_remain(char *remain, char **line)
{
	char	*eol_ptr;
	char	*tmp;

	eol_ptr = NULL;
	if (remain != NULL)
	{
		if (ft_strchr(remain, '\n'))
		{
			tmp = ft_strdup(remain);
			eol_ptr = ft_strchr(tmp, '\n');
			eol_ptr++;
			remain = ft_strcpy(remain, eol_ptr);
			*eol_ptr = '\0';
			*line = ft_strdup(tmp);
			free(tmp);
			tmp = NULL;
		}
		else
		{
			*line = ft_strdup(remain);
			remain[0] = '\0';
		}
	}
	else
		*line = ft_strnew(1);
	return (eol_ptr);
}

char	*ft_strjoin_with_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	if (tmp)
		free(tmp);
	return (s1);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			byte_read;
	char		*eol_ptr;
	static char	*remain;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 256)
		return (NULL);
	if (!(eol_ptr = check_remain(remain, &line)))
	{
		free(remain);
		remain = NULL;
	}
	while (!eol_ptr && (byte_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_read] = '\0';
		if ((eol_ptr = ft_strchr(buf, '\n')))
		{
			eol_ptr++;
			remain = ft_strdup(eol_ptr);
			*eol_ptr = '\0';
		}
		line = ft_strjoin_with_free(line, buf);
	}
	if (!ft_strlen(line) && !byte_read && !ft_strlen(remain))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

