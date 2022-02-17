/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:32:39 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/08 19:45:24 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_print_int(int n)
{
	char	c;

	c = '0' + n;
	write(1, &c, 1);
}

void	_print_seperator(int *arr, int size)
{
	int	i;
	int	flag;

	flag = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (arr[i] != 10 - size + i)
		{
			flag = 1;
		}
		i--;
	}
	if (flag == 1)
		write(1, ", ", 2);
}

void	_print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		_print_int(arr[i]);
		i++;
	}
	_print_seperator(arr, size);
}

void	comb(int *arr, int size, int idx, int r)
{
	int	i;

	i = 0;
	if (r == 0)
	{
		_print_arr(arr, size);
		return ;
	}
	while (i + idx < 10)
	{
		arr[size++] = i + idx;
		comb(arr, size, i + idx + 1, r - 1);
		size--;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[9];

	comb(arr, 0, 0, n);
}
