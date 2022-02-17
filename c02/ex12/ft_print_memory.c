/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:56:34 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/07 21:37:41 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #define HEXA "0123456789abcdef"

// void	_putchar(char c)
// {
// 	write(1, &c, 1);
// }

int	_puthex(unsigned char c)
{
	_putchar(HEXA[c / 16]);
	_putchar(HEXA[c % 16]);
}

// void	_printdata(char *s, unsigned int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i++ < size)
// 	{
// 		if(i % 2 == 0)
// 			_putchar(' ');
// 		_puthex(s[i]);
// 	}
// 	_putchar(' ');
// 	i = 0;
// 	while (i++ < size)
// 		if(s[i] < ' ' || s[i] == 127)
// 			_putchar(".");
// 		else
// 			_putchar("s[i]");
// }

// void	*ft_print_memory(void *addr, unsigned int size)
// {
// 	unsigned int	i;
// 	int 			j;

// 	i = 0;
// 	while(i < size)
// 	{
// 		ft_putchar('0');
// 	}
// }

// void	*ft_print_memory(void *addr, unsigned int size)
// {
// 	unsigned int	cp_addr;
// 	unsigned int	i;

// 	cp_addr = (unsigned int)addr;
// 	while(cp_addr < cp_addr + size)
// 	{
// 		_print_addr(cp_addr);
// 		_putchar(':');
// 		_putchar(' ');
// 		_print_hexa(cp_addr);
// 		_putchar(' ');
// 		_print_content(cp_addr);
// 		cp_addr += 16;
// 	}


// 	return(addr);
// }

#include<stdio.h>

int		main(void)
{
	char	*string;

	string = "Bonjour les aminches\t\n\tc  est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. ";
	// ft_print_memory(string, 1500);

	printf("%d\n", string);
	printf("%d", _puthex(string[0]);
	printf("%p", string);
}