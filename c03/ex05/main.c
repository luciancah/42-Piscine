#include<string.h>
#include<stdio.h>
#include"ft_strlcat.c"

int main (void)
{
	char src1[] = "What are you doing?";
	char dest1 [1000] = "012345";
	char src2[] = "What are you doing?";
	char dest2 [1000] = "012345";
	printf("%i \n", ft_strlcat(dest1, src1, 10));
	printf("%s \n", dest1);
	printf("%lu \n", strlcat(dest2, src2, 10));
	printf("%s \n", dest2);
}


// dest + src + '\0' 하는게 strlcat
// 이상적인 경우 size_t는 dest+src+1 만큼 주어져야 함
// i.e. size_t < dst -> return (src_len + size)
// i.e size_t >= dst -> return (src_len + dest_len)
