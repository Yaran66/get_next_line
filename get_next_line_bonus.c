/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:40:04 by wjasmine          #+#    #+#             */
/*   Updated: 2021/12/01 15:34:35 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static	char	*cut_remain_if_n(char **remain, char *eol_ptr, char **line)
{
	char	*tmp;

	tmp = ft_strdup(*remain);
	eol_ptr = ft_strchr(tmp, '\n');
	eol_ptr++;
	*remain = ft_strcpy(*remain, eol_ptr);
	*eol_ptr = '\0';
	*line = ft_strdup(tmp);
	free(tmp);
	tmp = NULL;
	return (eol_ptr);
}

static	char	*check_remain(char *remain, char **line)
{
	char	*eol_ptr;

	eol_ptr = NULL;
	if (remain != NULL)
	{
		if (ft_strchr(remain, '\n'))
			eol_ptr = cut_remain_if_n (&remain, eol_ptr, line);
		else
		{
			*line = ft_strdup(remain);
			remain[0] = '\0';
		}
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * (1));
		if (!*line)
			return (0);
		*line[0] = '\0';
	}
	return (eol_ptr);
}

static	char	*ft_strjoin_with_free(char *line, char *buf, char **remain)
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

static	void	free_null(char **str)
{
	free(*str);
	*str = NULL;
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			byte_read;
	char		*eol_ptr;
	static char	*remain[FD_MAX_MAC];

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 10240 || (read(fd, buf, 0) != 0))
		return (NULL);
	eol_ptr = check_remain(remain[fd], &line);
	if (!eol_ptr)
		free_null(&remain[fd]);
	byte_read = 1;
	while (!eol_ptr && byte_read)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
			return (0);
		buf[byte_read] = '\0';
		eol_ptr = ft_strchr(buf, '\n');
		line = ft_strjoin_with_free(line, buf, &remain[fd]);
	}
	if (!ft_strlen(line) && !byte_read && !ft_strlen(remain[fd]))
		free_null(&line);
	return (line);
}
