//
// Created by Aleksey Tvorogov on 21.11.2021.
//

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:46:52 by wjasmine          #+#    #+#             */
/*   Updated: 2021/11/22 22:55:47 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include<fcntl.h> //open

char	*check_remain(char *remain, char **line) // **line чтобы все что
// происходило с ней в check_remain изменяло оригинал.
{
	char	*eol_ptr;
	char	*tmp;
	//printf("%s\n", remain);
	eol_ptr = NULL;
	if(remain)
	{

		//tmp = ft_strdup(remain);
		//printf("temp: ""%s\n", tmp);
		if ((eol_ptr = ft_strchr((tmp = ft_strdup(remain)), '\n')))
		{
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
			//free(remain);
			//remain = NULL;
			//printf("%s\n", *line);
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
	char		*line; // строка которую возвращаем
	char	buf[BUFFER_SIZE + 1];
	int			byte_read; // сколько read вернул, чтобы поставть 0 в конце
	// прочитанного куска, который потом с помощью strjoin срастить, а также
	// получить 0 если читать нечего
	char		*eol_ptr; // указатель на \n ловим каретку
	static char *remain; // остаток от прочитанного, в зависимости от
	// величины буфера
	char	*tmp;
	if (fd < 0 || BUFFER_SIZE < 1 )
		return (NULL);
	eol_ptr = check_remain(remain, &line); // функция которая проверяет есть
	// ли остаток. если остаток есть, она вернет указатель, если нет то
	// вернет 0, также она зануляет line и eol_ptr при первом проходе.


	while (!eol_ptr && (byte_read = read(fd, buf, BUFFER_SIZE))) // если
		// eol_ptr == 0 и есть что читать входим.
	{
		buf[byte_read] = '\0';
		if ((eol_ptr = ft_strchr(buf, '\n'))) // проверяем нет ли каретки
		{
			eol_ptr++; // проходим за каретку
			remain = ft_strdup(eol_ptr); // записываем все что прочитали
			// после каретки в remain
			//printf("remain: ""%s\n", remain);
			*eol_ptr = '\0';//зануляем следующий символ после каретки, чтобы
			// strjoin записав каретку в новую line остановился
		}
		tmp = line;
		line = ft_strjoin(line, buf); // сращиваем то чем наполнли line , с
		// тем что прочитали в buf
		free(tmp);
	}
	//printf("%s\n", line);
	if (!ft_strlen(line) && !byte_read && !ft_strlen(remain)) // вот тут хочу
		// выводить 0, то есть когда line уже ноль, читать нечего, остаток
		// тоже ноль.
	{
		free(line);
		//free(remain);
		printf("null");
		return(NULL);
	}
	return(line);

}

int main()
{
	int		fd;
	char *line;
//	while((line = get_next_line(fd)))
//	{
//		printf("%s", line);
//	}
	fd = open("text.txt", O_RDONLY);
	printf("%d\n", fd);
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
}
