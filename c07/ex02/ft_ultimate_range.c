/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:31:50 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/19 13:28:52 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;
	int	size;

	i = 0;
	size = max - min;
	if (size <= 0)
	{
		*range = 0;
		return (0);
	}
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (-1);
	while (i < size)
	{
		arr[i] = min;
		i++;
		min++;
	}
	*range = arr;
	return (size);
}
