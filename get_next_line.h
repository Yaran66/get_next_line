/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:48:52 by wjasmine          #+#    #+#             */
/*   Updated: 2021/11/23 18:04:37 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40



# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *block, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, char *src);
void	ft_strclr(char *s);

#endif