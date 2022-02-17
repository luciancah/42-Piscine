#include <unistd.h>
#define HEXA "0123456789abcdef"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	temp;

	i = 0;
	while (str[i])
	{
		temp = (unsigned char) str[i];
		if (str[i] >= 32 && str[i] <= 126)
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_putchar('\\');
			ft_putchar(HEXA[temp / 16]);
			ft_putchar(HEXA[temp % 16]);
		}
		i++;
	}
}

int main (void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien?");
	ft_putchar('\n');
	ft_putstr_non_printable("Coucou tu vas bie\t\v");
	ft_putchar('\n');
	ft_putstr_non_printable("");
}
