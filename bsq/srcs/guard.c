/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guard.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:55:16 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/24 10:38:42 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guard.h"

void	_guard_data(t_map_data *data)
{
	if (!data)
		exit(1);
}

void	_guard_all(char *buf, t_map_data *data)
{
	free(buf);
	_free_data(data);
	exit(1);
}

void	_guard_buf(char *buf, t_map_data *data)
{
	if (!buf)
	{
		_free_data(data);
		exit(1);
	}
}

void	_guard_map(char *map, t_map_data *data)
{
	if (!map)
	{
		_free_data(data);
		exit(1);
	}
}

void	_guard_temp(char *temp, char *buf, t_map_data *data)
{
	if (!temp)
		_guard_all(buf, data);
}
