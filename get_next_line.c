/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:46:52 by wjasmine          #+#    #+#             */
/*   Updated: 2021/11/20 14:02:20 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include<fcntl.h>





char	*check_remain(char *remain, char **line)
{
	char	*eol_ptr;
	char	*tmp;
	//printf("%s\n", remain);
	eol_ptr = NULL;
	if(remain)
	{

		tmp = ft_strdup(remain);
		//printf("temp: ""%s\n", tmp);
		if ((eol_ptr = ft_strchr(tmp, '\n')))
		{
			eol_ptr++;
			remain = ft_strcpy(remain, eol_ptr);
			*eol_ptr = '\0';
			*line = ft_strdup(tmp);
			free(tmp);
		}
		else
		{
			*line = ft_strdup(remain);
			free(remain);
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
	int			byte_was_read;
	char		*eol_ptr;
	static char *remain;

	eol_ptr = check_remain(remain, &line);


	while (!eol_ptr && (byte_was_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_was_read] = '\0';
		if ((eol_ptr = ft_strchr(buf, '\n')))
		{
			eol_ptr++;
			remain = ft_strdup(eol_ptr);
			//printf("remain: ""%s\n", remain);
			*eol_ptr = '\0';
		}

		line = ft_strjoin(line, buf);
	}
	//printf("%s\n", line);
	if (ft_strlen(line) == 0)
		return(NULL);
	return(line);

}

int main()
{
	int		fd;
	char *line;
	while(line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	/*fd = open("text.txt", O_RDONLY);
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
	printf("%s", line);*/
	close(fd);
	return 0;
}
