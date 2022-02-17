#include<stdio.h>

int	_strlen(char *src)
{
	int	len;

	len = 0;
	while (src[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = _strlen(dest);
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

int	main()
{
	char src[] = "Benguerir";
	char dest[] = "1337 asdf";
	printf("%s", ft_strcat(dest, src));
}
