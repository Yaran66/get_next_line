/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:46:52 by wjasmine          #+#    #+#             */
/*   Updated: 2021/11/17 17:54:42 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include<fcntl.h>


char	*get_next_line(int fd)
{
	char	*line;
	static char	buf[10 + 1];
	int	byte_was_read;


	line =(char *)malloc(sizeof(char) * (1)); // or line = ft_strnew(1);
	line[0] = '\0';
	if(line == 0)
		return(0);
	while ((byte_was_read = read(fd, buf, 10)) && (!ft_strchr(line, '\n')))
	{
		buf[byte_was_read] = '\0';
		line = ft_strjoin(line, buf);
	}
	printf("%s\n", ((line - ft_strchr(line, '\n')));
	return(line);

}

int main()
{
	int		fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	line = get_next_line(fd);
	printf("%s\n", line);
	return 0;
}
