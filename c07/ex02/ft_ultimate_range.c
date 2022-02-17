/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:31:50 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/17 19:01:37 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;
	int size;

	i = 0;
	size = max - min;
	if (size <= 0)
		return ((int *)malloc((1) * sizeof(int)));
	arr = (int *)malloc((size) * sizeof(int));
	while (i < size)
	{
		arr[i] = min;
		i++;
		min++;
	}
	*range = arr;
	return (size);
}
