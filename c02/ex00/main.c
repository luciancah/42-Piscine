#include<stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


int	main()
{
	char src[] = "beautiful";
	char dest[2312891];
	printf("%s", (ft_strcpy(dest, src)));
}
