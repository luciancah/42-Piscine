/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:44:01 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/19 13:28:50 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	range;

	i = 0;
	range = max - min;
	if (min >= max)
		return (0);
	arr = (int *)malloc((max - min) * sizeof(int));
	if (!arr)
		return (0);
	while (i < range)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
