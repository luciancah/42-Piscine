#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	flag;

	flag = 0;
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			flag = 1;
		else
			return (0);
		str++;
	}
	return (flag);
}

int	main()
{
       printf("%d", ft_str_is_uppercase("ABCDEFGH"));
       printf("\n%d", ft_str_is_uppercase("ABCDEFGHaI"));
       printf("\n%d", ft_str_is_uppercase("-_134556ABCDEFGaH67"));
}