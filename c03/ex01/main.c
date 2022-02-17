#include "ft_strncmp.c"
#include <string.h>
#include <stdio.h>

int	main()
{
	printf("%d", ft_strncmp("Hello", "Helllll", 4));
	printf("%d", strncmp("Hello", "Helllll", 4));

	char str1[500] = "Hello World!";
	char str2[500] = "Hello Worl";

	printf("----ex01----\n");
	printf("%s\n%s\n",str1, str2);
	printf("Compare\n");
	printf("%d : %d\n", strncmp(str1, str2, 5), ft_strncmp(str1, str2, 5));
	printf("%d : %d\n", strncmp(str1, str2, 0), ft_strncmp(str1, str2, 0));
	// 이거 확인하기
	printf("%d : %d\n", strncmp(str1, str2, 30), ft_strncmp(str1, str2, 30));
	printf("\n");
}