#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	flag;

	flag = 0;
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			flag = 1;
		else
			return (0);
		str++;
	}
	return (flag);
}

int	main()
{
	printf("%d", ft_str_is_lowercase("abcdefghijkl"));
    printf("\n%d", ft_str_is_lowercase("abcAdefghijkl"));
    printf("\n%d", ft_str_is_lowercase("-_134556efSghij67"));
}
