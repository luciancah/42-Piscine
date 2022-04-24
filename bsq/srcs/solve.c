/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:37:23 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/24 10:36:34 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

int	_min(int i, int j, int k)
{
	if (i <= j && i <= k)
		return (i);
	else if (j <= i && j <= k)
		return (j);
	return (k);
}

void	_init(int *a, int *b, int a_value, int b_value)
{
	*a = a_value;
	*b = b_value;
}

void	_printmap(int len, t_point pos, int size, t_map_data *data)
{
	int		i;
	int		j;
	int		k;
	char	*map;

	map = (char *)malloc(sizeof(char) * size);
	_guard_map(map, data);
	_init(&i, &k, -1, 0);
	while (++i < data->y)
	{
		j = -1;
		while (++j < data->x)
		{
			if ((j >= pos.x - (len - 1) && j <= pos.x) \
			&& (i >= pos.y - (len - 1) && i <= pos.y))
				map[k++] = data->fill;
			else if (data->max_width[i][j] == 0)
				map[k++] = data->obstacle;
			else
				map[k++] = data->empty;
		}
		map[k++] = '\n';
	}
	write(1, map, size);
	free(map);
}

void	solve(t_map_data *data)
{
	t_point	max_pos;
	int		max_len;
	int		i;
	int		j;

	_init(&i, &max_len, -1, -1);
	while (++i < data->y)
	{
		j = -1;
		while (++j < data->x)
		{
			if (data->max_width[i][j] == 1 && i > 0 && j > 0)
			{
				data->max_width[i][j] = _min(data->max_width[i - 1][j], \
				data->max_width[i][j - 1], data->max_width[i - 1][j - 1]) + 1;
			}
			if (max_len < data->max_width[i][j])
			{
				max_len = data->max_width[i][j];
				max_pos.x = j;
				max_pos.y = i;
			}
		}
	}
	_printmap(max_len, max_pos, (data->x + 1) * data->y, data);
}
