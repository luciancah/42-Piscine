

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void recur(int num_array[])
{
    int cur = 0;
    while(cur < 1)
    {
        num_array[1]++;
        if (num_array[1] > 9)
        {
            num_array[0]++;
            num_array[1] = num_array[0] + 1;
            if (num_array[1] > 9)
            {
                return ;
            }
        }
        cur++;
    }

    cur = 0;
    while (cur <= 1)
    {
        char a = num_array[cur] + '0';
        write(1, &a, 1);
        cur++;
    }

    write(1, " ", 1);

    if(num_array[0] < 9)
    {
        recur(num_array, 2);
    }
}

void ft_print_combn(int n)
{
    int num_array[n];

    int cur = 0;
    while (cur < n)
    {
        num_array[cur] = 0;
        cur++;
    }

    recur(num_array);
}

int main()
{
    ft_print_combn(2);
}

