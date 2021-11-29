//
// Created by Aleksey Tvorogov on 20.11.2021.
//
/*
#include "get_next_line.h"
#include <stdio.h>
#include<fcntl.h>

char	*check_remain(char *remain, char **line)
{
	char	*eol_ptr;
	char	*tmp;
	eol_ptr = NULL;
	if(remain != NULL)
	{
		//printf("%s\n", remain);
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
			//ft_strclr(remain);
			remain[0] = '\0';
			//free(remain);
			//remain = NULL;
		}
	}
	else
	{
		if (!(*line =(char *)malloc(sizeof(char) * (1))))
			return(0);
		line[0][0] = '\0';
	}
	return(eol_ptr);
}

char	*get_next_line(int fd)
{
	char		*line;
	char	buf[BUFFER_SIZE + 1];
	int			byte_read;
	char		*eol_ptr;
	static char *remain;
	char	*tmp;

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
		tmp = line;
		line = ft_strjoin(line, buf);
		if (tmp)
			free(tmp);
	}

	if (!ft_strlen(line) && !byte_read && !ft_strlen(remain))
	{
		free(line);
		//free(remain);
		//printf("null");
		return(NULL);
	}
	return(line);
}

/*int main()
{
	int		fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	printf("%d\n", fd);
	 while((line = get_next_line(fd)))
	{
		printf("%s", line);
	}
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return 0;
}*/
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

char	*cut_remain(char *remain, char **line)
{
	char	tmp;

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
}

char	*ft_strjoin_with_free(char *line, char *buf, char **remain)
{
	char	*tmp;
	char	*eol_ptr;

	tmp = line;
	if (ft_strchr(buf, '\n'))
	{
		eol_ptr = ft_strchr(buf, '\n');
		eol_ptr++;
		*remain = ft_strdup(eol_ptr);
		*eol_ptr = '\0';
	}
	line = ft_strjoin(line, buf);
	if (tmp)
		free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			byte_read;
	char		*eol_ptr;
	static char	*remain;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 256 || (read(fd, buf, 0) != 0))
		return (NULL);
	eol_ptr = check_remain(remain, &line);
	if (!eol_ptr)
	{
		free(remain);
		remain = NULL;
	}
	byte_read = 1;
	while (!eol_ptr && byte_read)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
			return (0);
		buf[byte_read] = '\0';
		eol_ptr = ft_strchr(buf, '\n');
		line = ft_strjoin_with_free(line, buf, &remain);
	}
	if (!ft_strlen(line) && !byte_read && !ft_strlen(remain))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/*int main()
{
	int		fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	printf("%d\n", fd);
	while((line = get_next_line(fd)))
	{
		printf("%s", line);
	}
	close(fd);
	return 0;
}*/