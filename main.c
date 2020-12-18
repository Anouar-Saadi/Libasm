#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(char *str);
char *ft_strcpy(char *dst, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

int		test_strlen()
{
	int a;
	int s;

	char *str;
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str = "hello, World!";
	str1 = "";
	str2 = NULL;
	str3 = "hello, World! This is Africa";
	str4 = "hello, World!";
	s = strlen(str3);
	printf("%d %s\n", s, str3);
	a = ft_strlen(str3);
	printf("%d %s\n", a, str3);
	return 0;
}

int test_strcpy()
{
	char *src00 = "";
	char *src01 = "Hello, World!";
	char *src02 = NULL;
	char *src03 = "abcdefghijklmnopqrstuvwxyz";
	char *src04 = "1337FUTUREISLOADING!";
	char dest[100];


	strcpy(dest, src00);
	printf("|%s|, |%s|\n", src00, dest);
	ft_strcpy(dest, src00);
	printf("|%s|, |%s|\n", src00, dest);
	strcpy(dest, src01);
	printf("|%s|, |%s|\n", src01, dest);
	ft_strcpy(dest, src01);
	printf("|%s|, |%s|\n", src01, dest);
	strcpy(dest, src02);
	printf("|%s|, |%s|\n", src02, dest);
	ft_strcpy(dest, src02);
	printf("|%s|, |%s|\n", src02, dest);
	strcpy(dest, src03);
	printf("|%s|, |%s|\n", src03, dest);
	ft_strcpy(dest, src03);
	printf("|%s|, |%s|\n", src03, dest);
	strcpy(dest, src04);
	printf("|%s|, |%s|\n", src04, dest);
	ft_strcpy(dest, src04);
	printf("|%s|, |%s|\n", src04, dest);
	return (0);
}

int	test_strcmp()
{
	int i;
	
	//test_strcpy();
	i = strcmp("abcdefghijklmnopqrstuvwxyz","abcdefghijklmnopqrstuvwxy");
	printf("alphabet|%d|\n", i);
	i = ft_strcmp("abcdefghijklmnopqrstuvwxyz","abcdefghijklmnopqrstuvwxy");
	printf("alphabet|%d|\n", i);
	i = strcmp("hello","henlo");
	printf("str|%d|\n", i);
	i = ft_strcmp("hello","henlo");
	printf("str|%d|\n", i);
	i = strcmp("","");
	printf("empty|%d|\n", i);
	i = strcmp("","");
	printf("empty|%d|\n", i);
	i = strcmp(NULL,"abcdefghijklmnopqrstuvwxy");
	printf("NULL|%d|\n", i);
	i = ft_strcmp(NULL,"abcdefghijklmnopqrstuvwxy");
	printf("NULL|%d|\n", i);
	return 0;
}

int	test_write()
{
	int fd;
	int fd1;
	char *buffer;


	buffer = "Hello, Africa!";
	fd = open("file.txt", O_CREAT | O_RDWR);
	write(fd, buffer, ft_strlen(buffer));
	close(fd);
	fd1 = open("file1.txt", O_CREAT | O_RDWR);
	ft_write(fd1, buffer, ft_strlen(buffer));
	close(fd1);
	return 0;
}

int test_read()
{
	int fd;
	char buff[10];
	ssize_t i;
	//fd = open("file.tt", O_RDONLY);
	fd = 1;
	i = ft_read(fd, buff, 10);
	close(fd);
	printf("|%zd| |%s|\n", i, buff);

	return 0;
}

int	main()
{
	char		*str;
	char			*l;
	
	test_read();
	//str = strdup("sdgfhjsafguasufdhxzhfhhxzcfhxz");
	//printf("copy|%s| |%d|\n", str,ft_strlen(str));
	//l = ft_strdup(str);
	//printf("copy|%s| |%d|\n", l, ft_strlen(l));
	return 0;
}
