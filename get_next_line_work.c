//
// Created by Aleksey Tvorogov on 20.11.2021.
//

#include "get_next_line.h"
#include <stdio.h>
#include<fcntl.h>

char	*get_next_line(int fd)
{
	char		*line;
	char	buf[10 + 1];
	int			byte_was_read;
	char		*eol_ptr;
	int			flag;
	static char *remain;

	flag = 1;

	 if (!(line =(char *)malloc(sizeof(char) * (1)))) //line = ft_strnew(1);
		return(0);
	if (remain)
	{
		line = ft_strdup(remain);
		free(remain);
	}
	else line[0] = '\0';

	while (flag && (byte_was_read = read(fd, buf, 10)))
	{
		buf[byte_was_read] = '\0';
		if ((eol_ptr = ft_strchr(buf, '\n')))
		{
			flag = 0;
			eol_ptr++;
			remain = ft_strdup(eol_ptr);
			printf("remain: ""%s\n", remain);
			*eol_ptr = '\0';
		}

		line = ft_strjoin(line, buf);
	}
	//printf("%s\n", line);
	return(line);

}

int main()
{
	int		fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	//while ((line = get_next_line(fd)))
//		printf("%s\n", line);
	close(fd);
	return 0;
}
