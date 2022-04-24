/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:37:01 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/19 11:41:00 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		_arr_len(int num, int base_len);
char	*ft_putnbr_base(int nbr, char *base, int base_count);

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
		else if (base[i] == '\n' || base[i] == '\t' || \
			base[i] == '\v' || base[i] == '\r' || base[i] == '\f')
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

long long	_get_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			base_count;
	int			sign_flag;
	long long	answer;

	base_count = _base_count(base);
	if (base_count == 0)
		return (0);
	sign_flag = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign_flag *= -1;
		str++;
	}
	answer = 0;
	while (_get_base(*str, base) != -1)
	{
		answer *= base_count;
		answer += _get_base(*str, base);
		str++;
	}
	return (answer * sign_flag);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	deci;

	if (!_base_count(base_from) || !_base_count(base_to))
		return (0);
	deci = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(deci, base_to, _base_count(base_to)));
}
