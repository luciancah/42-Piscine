#include <stdio.h>
#include "ft_find_next_prime.c"

int main()
{
	printf("2 : %d\n", ft_find_next_prime(-123));
	printf("7 : %d\n", ft_find_next_prime(6));
	printf("11 : %d\n", ft_find_next_prime(11));
	printf("2 : %d\n", ft_find_next_prime(0));
	printf("31 : %d\n", ft_find_next_prime(30));
	printf("97 : %d\n", ft_find_next_prime(90));
}
