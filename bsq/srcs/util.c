/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:57:14 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/24 10:36:23 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	_is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

int	_valid_map(char *map, t_map_data *data)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	height = 0;
	while (map[i])
	{
		width = 0;
		while (map[i] != '\n')
		{
			if (map[i] != data->obstacle && map[i] != data->empty)
				return (0);
			width++;
			i++;
		}
		if (width != data->x)
			return (0);
		height++;
		i++;
	}
	if (height != data->y)
		return (0);
	return (1);
}

int	_atoi(char *str, int n)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num);
}

void	_free_data(t_map_data *data)
{
	int	i;

	i = 0;
	if (data->max_width)
	{
		while (i < data->y)
		{
			if (data->max_width[i])
				free(data->max_width[i]);
			i++;
		}
		free(data->max_width);
	}
	free(data);
}
