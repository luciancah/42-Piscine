/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:58:39 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/13 18:00:39 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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
			base[i] == '\v' || base[i] == '\r')
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
