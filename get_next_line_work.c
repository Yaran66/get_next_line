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