#include <stdio.h>
#include "ft_is_prime.c"

int main()
{
		printf("1 : %d\n", ft_is_prime(2147483647));
		printf("0 : %d\n", ft_is_prime(0));
		printf("0 : %d\n", ft_is_prime(1));
		printf("0 : %d\n", ft_is_prime(-1));
		printf("1 : %d\n", ft_is_prime(29));
		printf("1 : %d\n", ft_is_prime(11));
}
