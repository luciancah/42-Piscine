#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	flag;

	flag = 0;
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
			flag = 1;
		else
			return (0);
		str++;
	}
	return (flag);
}

int	main()
{
	printf("%d", ft_str_is_printable("ABDELKFSCO?I340990%"));
	printf("\n%d", ft_str_is_printable("\n\t\v\f"));
}
