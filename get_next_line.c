/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:01:51 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/13 21:43:31 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include "stdio.h"

int		ft_check(char **stat, char **line)
{
	char *pos_n;

	if (*stat)
	{
		if ((pos_n = ft_strchr(*stat, '\n')))
		{
			*pos_n++ = '\0';
			if(!(*line = ft_strdup(*stat))) {
				free(*stat);
				*stat = NULL;
				return (-1);
			}
//			*stat = 	ft_strdup(pos_n);
			ft_strlcpy(*stat,pos_n);//lick мб лучше копировать а не дюпать
			return (0);
		}
		else
		{
			*line = ft_strdup(*stat);
			free(*stat);
			*stat = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (1);
}

int		ft_reed(char **stat, char **line, int fd)
{
	int r_b;
	char *pos_n;
	char *bf;
	char *fre;

	bf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	pos_n = NULL;
	while (!pos_n && (r_b = read(fd, bf, BUFFER_SIZE)))
	{
		bf[r_b] = '\0';
		if ((pos_n = ft_strchr(bf, '\n'))) {
			*pos_n++ = '\0';
			*stat = ft_strdup(pos_n);//lick
//			fre = *line;
//			*line = ft_strjoin(*line, bf);// очистить line
//			free(fre);
//			fre = NULL;
		}
		fre = *line;
		*line = ft_strjoin(*line, bf);// очистить line
		free(fre);
		fre = NULL;
	}
	free(bf);
	if (r_b == 0) {
		free(*stat);
		*stat = NULL;
		return (0);
	}
	return (1);
//	return (r_b || ft_strlen(*stat) || ft_strlen(*line) ? 1 : 0);
}


int		get_next_line(int fd, char **line)
{
	char *bf;
	static char *stat[1024];

	if (fd < 0 || !line || !(bf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char))) || (read(fd, bf, 0)) < 0)
		return (-1);

	if (ft_check(&stat[fd], line))// добавить очистку памяти в случае получания -1
		return (ft_reed(&stat[fd], line, fd));// добавить очистку памяти в случае получания -1
	return (1);
}







//int		get_next_line(int fd, char **line)
//{
//	char *bf;
//	int r_b;
//	char *pos_n;
//	char *fre;
//	static char *stat;
//
//	bf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
//
//	pos_n = check_stat(stat, line);
//	while (!pos_n && (r_b = read(fd, bf, BUFFER_SIZE)))
//	{
//		bf[r_b] = '\0';
//		if ((pos_n = ft_strchr(bf,'\n')))
//		{
//			*pos_n++ = '\0';
//			stat = ft_strdup(pos_n);
//		}
//		fre = *line;
//		*line = ft_strjoin(*line, bf);
//		free(fre);
//	}
//	return ((r_b || ft_strlen(stat) || ft_strlen(*line) ? 1 : 0));
//}
