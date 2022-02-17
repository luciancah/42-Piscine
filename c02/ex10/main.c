#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(src);
	i = 0;
	if(size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

int	main()
{
	char src[] = "World!";
	char dest[4] = "Hel";
	char src2[] = "World!";
	char dest2[4] = "Hel";
	printf("%d | %s\n", ft_strlcpy(dest, src, 0), dest);
	printf("%lu | %s", strlcpy(dest2, src2, ), dest2);
}
