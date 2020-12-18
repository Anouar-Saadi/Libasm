/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:58:13 by asaadi            #+#    #+#             */
/*   Updated: 2020/12/18 14:37:25 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void		test_strlen(char *str)
{
	int a;
	int s;

	s = strlen(str);
	printf("sys_strlen |%d| %s\n", s, str);
	a = ft_strlen(str);
	printf("asm_strlen |%d| %s\n", a, str);
}

void		test_strcmp(void)
{
	int		i;
	char	*s1[5];
	char	*s2[5];

	s1[0] = "";
	s1[1] = "Hello, World!";
	s1[2] = NULL;
	s1[3] = "abcdefghijklmnopqrstuvwxyz";
	s1[4] = "1337FUTUREISLOADING!";
	s2[0] = "";
	s2[1] = "Hello, World!";
	s2[2] = NULL;
	s2[3] = "abcdefghijklmnopqrstuvwxyz";
	s2[4] = "1337FUTUREISLOADING!";
	i = strcmp(s1[0], s2[0]);
	printf("sys_strcmp |%d|\n", i);
	i = ft_strcmp(s1[0], s2[0]);
	printf("asm_strcmp |%d|\n", i);
}

void		test_write(void)
{
	int		fd;
	int		fd1;
	char	*buffer;
	ssize_t	i;

	buffer = "Hello, Africa!";
	fd = open("file.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	i = write(fd, buffer, ft_strlen(buffer));
	close(fd);
	fd1 = open("file1.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	i = ft_write(fd1, buffer, ft_strlen(buffer));
	close(fd1);
}

void		test_read(void)
{
	int		fd;
	char	buff[5];
	ssize_t	i;

	fd = open("file.txt", O_RDONLY);
	i = read(fd, buff, 5);
	close(fd);
	printf("read |%zd| |%s|\n", i, buff);
}

int			main(void)
{
	char *str[5];
	char *sy_cpy;
	char *my_cpy;
	char dest[100];

	str[0] = "";
	str[1] = "Hello, World!";
	str[2] = NULL;
	str[3] = "abcdefghijklmnopqrstuvwxyz";
	str[4] = "1337FUTUREISLOADING!";
	test_strlen(str[0]);
	strcpy(dest, str[0]);
	printf("sys_cpy |%s|, |%s|\n", str[0], dest);
	ft_strcpy(dest, str[0]);
	printf("asm_cpy |%s|, |%s|\n", str[0], dest);
	test_strcmp();
	test_write();
	test_read();
	sy_cpy = strdup(str[0]);
	printf("sys_copy|%s| |%d|\n", sy_cpy, ft_strlen(sy_cpy));
	my_cpy = ft_strdup(str[0]);
	printf("asm_copy|%s| |%d|\n", my_cpy, ft_strlen(my_cpy));
	return (0);
}
