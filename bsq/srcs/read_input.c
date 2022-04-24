/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:14:38 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/24 10:36:39 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_input.h"

int	_read_stdin(t_map_data *data)
{
	int		i;
	char	*buf;

	i = 0;
	buf = (char *)malloc(sizeof(char) * BUF_SIZE + 1);
	_guard_buf(buf, data);
	while (read(0, &buf[i], 1))
		i++;
	return (_parse(buf, data));
}

char	*_init_buf(t_map_data *data)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char));
	_guard_buf(buf, data);
	*buf = '\0';
	return (buf);
}

int	_read_file(char *file_name, t_map_data *data)
{
	int		fd;
	int		bytes;
	char	*buf;
	char	*temp;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	buf = _init_buf(data);
	while (1)
	{
		temp = (char *)malloc(sizeof(char) * BUF_SIZE + 1);
		_guard_temp(temp, buf, data);
		bytes = read(fd, temp, BUF_SIZE);
		if (bytes <= 0)
		{
			free(temp);
			break ;
		}
		temp[bytes] = '\0';
		buf = _strjoin(buf, temp);
		_guard_buf(buf, data);
	}
	close(fd);
	return (_parse(buf, data));
}
