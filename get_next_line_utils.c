/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:51:35 by wjasmine          #+#    #+#             */
/*   Updated: 2021/11/17 14:19:26 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == ((char)c))
		{
			return (((char *)s) + i);
		}
		i++;
	}
	if (c == 0)
	{
		return (((char *)s) + i);
	}
	return (0);
}

void	ft_bzero(void *block, size_t size)
{
	while (size--)
	{
		((unsigned char *)block)[size] = (unsigned char)0;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	ptr = malloc (sizeof(*s1) * (ft_strlen(s1) + 1));
	i = 0;
	if (ptr == 0)
	{
		return (0);
	}
	while (s1[i] != 0)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	newstr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstr == 0)
		return (0);
	i = 0;
	while (*s1)
	{
		newstr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		newstr[i] = *s2;
		s2++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
