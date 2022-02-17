/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:41:29 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/13 17:01:54 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	_base_count(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (i);
}

void	_print_base(long long n, char *base, int base_count)
{
	if (n >= base_count)
		_print_base(n / base_count, base, base_count);
	write(1, &base[n % base_count], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_count;
	long long	longnbr;

	longnbr = (long long) nbr;
	base_count = _base_count(base);
	if (base_count == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		longnbr *= -1;
	}
	_print_base(longnbr, base, base_count);
}
