///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   main.c                                             :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2019/10/22 17:41:13 by mchardin          #+#    #+#             */
///*   Updated: 2020/11/13 21:23:21 by cveeta           ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include <fcntl.h>
//#include <sys/stat.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//
//int				get_next_line(int fd, char **line);
//
//int main()
//{
//	int             fd;
//	int             i;
//	int             j;
//	char    		*line = 0;
//	char			*lineadress[66];
//
//	j = 1;
//	/*
//	printf("\n==========================================\n");
//	printf("========== TEST 1 : The Alphabet =========\n");
//	printf("==========================================\n\n");
//
//	if (!(fd = open("files/alphabet", O_RDONLY)))
//	{
//		printf("\nError in open\n");
//		return (0);
//	}
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
//		printf("|%s\n", line);
//		lineadress[j - 1] = line;
//		j++;
//	}
//	printf("|%s\n", line);
//	free(line);
//	close(fd);
//
//	if (i == -1)
//		printf ("\nError in Fonction - Returned -1\n");
//	else if (j == 66)
//		printf("\nRight number of lines\n");
//	else if (j != 66)
//		printf("\nNot Good - Wrong Number Of Lines\n");
//	while (--j > 0)
//		free(lineadress[j - 1]);
//	j = 1;
//
//	printf("\n==========================================\n");
//	printf("========= TEST 2 : Empty Lines ===========\n");
//	printf("==========================================\n\n");
//
//	if (!(fd = open("files/empty_lines", O_RDONLY)))
//	{
//		printf("\nError in open\n");
//		return (0);
//	}
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
//		printf("|%s\n", line);
//		free(line);
//		j++;
//	}
//	printf("|%s\n", line);
//	free(line);
//	close(fd);
//
//	if (i == -1)
//		printf ("\nError in Fonction - Returned -1\n");
//	else if (j == 9)
//		printf("\nRight number of lines\n");
//	else if (j != 9)
//		printf("\nNot Good - Wrong Number Of Lines\n");
//	j = 1;
//	printf("\n==========================================\n");
//	printf("======== TEST 3 : The Empty File =========\n");
//	printf("==========================================\n\n");
//
//	if (!(fd = open("files/empty_file", O_RDONLY)))
//	{
//		printf("\nError in open\n");
//		return (0);
//	}
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
//		printf("|%s\n", line);
//		free(line);
//		j++;
//	}
//	printf("|%s\n", line);
//	free(line);
//	close(fd);
//
//	if (i == -1)
//		printf ("\nError in Fonction - Returned -1\n");
//	else if (j == 1)
//		printf("\nRight number of lines\n");
//	else if (j != 1)
//		printf("\nNot Good - Wrong Number Of Lines\n");
//	j = 1;
//	printf("\n==========================================\n");
//	printf("========= TEST 4 : One New Line ==========\n");
//	printf("==========================================\n\n");
//
//	if (!(fd = open("files/1_newline", O_RDONLY)))
//	{
//		printf("\nError in open\n");
//		return (0);
//	}
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
//		printf("|%s\n", line);
//		free(line);
//		j++;
//	}
//	printf("|%s\n", line);
//	free(line);
//	close(fd);
//
//	if (i == -1)
//		printf ("\nError in Fonction - Returned -1\n");
//	else if (j == 2)
//		printf("\nRight number of lines\n");
//	else if (j != 2)
//		printf("\nNot Good - Wrong Number Of Lines\n");
//	j = 1;
//	printf("\n==========================================\n");
//	printf("========= TEST 5 : Four New Lines ========\n");
//	printf("==========================================\n\n");
//
//	if (!(fd = open("files/4_newlines", O_RDONLY)))
//	{
//		printf("\nError in open\n");
//		return (0);
//	}
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
//		printf("|%s\n", line);
//		free(line);
//		j++;
//	}
//	printf("|%s\n", line);
//	free(line);
//	close(fd);
//
//	if (i == -1)
//		printf ("\nError in Fonction - Returned -1\n");
//	else if (j == 5)
//		printf("\nRight number of lines\n");
//	else if (j != 5)
//		printf("\nNot Good - Wrong Number Of Lines\n");
//	j = 1;
//	printf("\n==========================================\n");
//	printf("============== TEST 6 : 42 ===============\n");
//	printf("==========================================\n\n");
//
//	if (!(fd = open("files/41_char", O_RDONLY)))
//	{
//		printf("\nError in open\n");
//		return (0);
//	}
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
//		printf("|%s\n", line);
//		free(line);
//		j++;
//	}
//	printf("|%s\n", line);
//	free(line);
//	close(fd);
//	if (!(fd = open("files/42_char", O_RDONLY)))
//	{
//		printf("\nError in open\n");
//		return (0);
//	}
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
//
//		printf("|%s\n", line);
//		free(line);
//		j++;
//	}
//	printf("|%s\n", line);
//	free(line);
//	close(fd);
//	if (!(fd = open("files/43_char", O_RDONLY)))
//	{
//		printf("\nError in open\n");
//		return (0);
//	}
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
//		printf("|%s\n", line);
//		free(line);
//		j++;
//	}
//	printf("|%s\n", line);
//	free(line);
//	close(fd);
//
//	if (i == -1)
//		printf ("\nError in Fonction - Returned -1\n");
//	else if (j == 1)
//		printf("\nRight number of lines\n");
//	else if (j != 1)
//		printf("\nNot Good - Wrong Number Of Lines\n");
//	 */
//	j = 1;
//	printf("\n==========================================\n");
//	printf("============= TEST 7 : Marge =============\n");
//	printf("==========================================\n\n");
//
//	int fd2;
//
//	if (!(fd = open("files/half_marge_top", O_RDONLY)))
//	{
//		printf("\nError in open\n");
//		return (0);
//	}
//	if (!(fd2 = open("files/half_marge_bottom", O_RDONLY)))
//	{
//		printf("\nError in open\n");
//		return (0);
//	}
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
//		printf("%d|%s\n", i, line);
//		free(line);
//		j++;
//	}
//	free(line);
//	//line = "";
//	//printf("hey%shey\n", line);
//	while ((i = get_next_line(fd2, &line)) > 0)
//	{
//		printf("%s\n", line);
//		free(line);
//		j++;
//	}
//	printf("%s\n", line);
//	free(line);
//	close(fd);
//	close(fd2);
///*
//	if (i == -1)
//		printf ("\nError in Fonction - Returned -1\n");
//	else if (j == 25)
//		printf("\nRight number of lines\n");
//	else if (j != 25)
//		printf("\nNot Good - Wrong Number Of Lines\n");*/
//	j = 1;
//	printf("\n==========================================\n");
//	printf("========= TEST 8 : Wrong Input ===========\n");
//	printf("==========================================\n\n");
//
//	if (get_next_line(180, &line) == -1)
//		printf("Well Done, you return -1 if no FD\n\n");
//	else
//		printf("Not Good, you don't return -1 if no FD\n\n");
//	return (0);
//}

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include "stdio.h"

int main() {
	int fd1, fd2;
	char *line;
	char bf[1000000];
	fd1 =  open("text2.txt", O_RDONLY);
	fd2 = open("text.txt", O_RDONLY);

	//printf(">>>|%d", (read(6, bf, 0)));



	while (get_next_line(fd1,&line)) {
		printf("%s\n", line);
		free(line);
	}
	//fd1 = open("text.txt", O_RDONLY);
	//printf("%s\n", line);
	free(line);

	while (get_next_line(fd2,&line)) {
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
////	printf("--------------------------------------------------------------------------------\n");
//
//	while (get_next_line(fd2,&line)) {
//		printf("-|%s\n", line);
//		free(line);
//	}

//	get_next_line(fd, &line);
//	printf(">|%s\n", line);
//	free(line);
}