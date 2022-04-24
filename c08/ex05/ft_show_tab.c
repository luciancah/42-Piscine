/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:21:44 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/19 20:25:21 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	_putint(int nb, int is_negative)
{
	char	to_print;

	if (nb == 0)
	{
		if (is_negative)
			write(1, "-", 1);
		return ;
	}
	_putint(nb / 10, is_negative);
	to_print = (nb % 10) + '0';
	write(1, &to_print, 1);
}

void	_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
	else
	{
		if (nb < 0)
			_putint(-nb, 1);
		else
			_putint(nb, 0);
	}
}

void	_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		_putstr((par + i)->str);
		write(1, "\n", 1);
		_putnbr((par + i)->size);
		write(1, "\n", 1);
		_putstr((par + i)->copy);
		write(1, "\n", 1);
		i++;
	}
	return ;
}
