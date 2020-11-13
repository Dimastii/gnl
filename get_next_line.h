/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:09:58 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/13 21:24:55 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
#define GET_NEXT_LINE_GET_NEXT_LINE_H
#define BUFFER_SIZE 9999
#include "unistd.h"
#include "stdlib.h"

typedef struct		s_list
{
	char			content;
	struct s_list	*next;
}					t_list;

size_t		ft_strlen(const char *s);
char	*ft_strchr(const char *string, int symbol);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s);
size_t		ft_strlcpy(char *dst, const char *src);

#endif
