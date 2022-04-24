/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:42:09 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/19 11:51:24 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	_base_count(char *base);

int	_arr_len(int num, int base_len)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		num *= -1;
		len = 1;
	}
	while (num / base_len)
	{
		len++;
		num /= base_len;
	}
	return (len + 1);
}

char	*ft_putnbr_base(int nbr, char *base, int base_count)
{
	int			arr_len;
	int			i;
	long long	longnbr;
	char		*answer;

	longnbr = (long long) nbr;
	arr_len = _arr_len(nbr, base_count);
	answer = (char *)malloc((arr_len) * sizeof(char));
	if (!answer)
		return (0);
	if (nbr < 0)
		longnbr *= -1;
	i = 0;
	while (i < arr_len)
	{
		answer[arr_len - i - 1] = base[longnbr % base_count];
		longnbr /= base_count;
		i++;
	}
	answer[arr_len] = '\0';
	if (nbr < 0)
		answer[0] = '-';
	return (answer);
}
