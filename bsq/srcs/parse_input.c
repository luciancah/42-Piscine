/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:36:34 by siseo             #+#    #+#             */
/*   Updated: 2022/02/24 10:38:51 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int	_first_line(char *map, t_map_data *data)
{
	int	eol;
	int	i;

	eol = 0;
	i = 0;
	while (map[eol] && map[eol] != '\n')
		eol++;
	if (eol < 4)
		return (0);
	data->fill = map[eol - 1];
	data->obstacle = map[eol - 2];
	data->empty = map[eol - 3];
	data->y = _atoi(map, (eol - 3));
	if (data->y <= 0 || data->obstacle == data->empty
		|| data->obstacle == data->fill || data->fill == data->empty)
		return (0);
	if (!_is_printable(data->obstacle) || !_is_printable(data->fill) || \
	!_is_printable(data->empty))
		return (0);
	data->x = 0;
	while (map[data->x + eol + 1] && map[data->x + eol + 1] != '\n')
		data->x++;
	if (data->x == 0)
		return (0);
	return (1);
}

void	_init_max_width(char *map, char *buf, t_map_data *data)
{
	int	i;
	int	j;
	int	k;

	data->max_width = (int **)malloc(sizeof(int *) * data->y);
	if (!data->max_width)
		_guard_all(buf, data);
	i = -1;
	k = 0;
	while (++i < data->y)
	{
		j = -1;
		data->max_width[i] = (int *)malloc(sizeof(int) * data->x);
		if (!data->max_width[i])
			_guard_all(buf, data);
		while (++j < data->x)
		{
			if (map[k] == data->empty)
				data->max_width[i][j] = 1;
			if (map[k] == data->obstacle)
				data->max_width[i][j] = 0;
			k++;
		}
		k++;
	}
}

int	_parse(char *buf, t_map_data *data)
{
	char	*map;
	int		valid;

	map = buf;
	while (*map != '\n')
		map++;
	map++;
	valid = 0;
	if (_first_line(buf, data) && _valid_map(map, data))
	{
		_init_max_width(map, buf, data);
		solve(data);
		valid = 1;
	}
	free(buf);
	return (valid);
}
