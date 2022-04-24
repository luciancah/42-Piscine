/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:38:41 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/24 10:40:25 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	main_stdin(void)
{
	t_map_data	*data;

	data = (t_map_data *)malloc(sizeof(t_map_data));
	_guard_data(data);
	data->max_width = 0;
	if (_read_stdin(data) == 0)
		write(2, "map error\n", 10);
	_free_data(data);
}

int	main(int argc, char **argv)
{
	int			i;
	t_map_data	*data;

	if (argc == 1)
		main_stdin();
	else
	{
		i = 1;
		while (i < argc)
		{
			data = (t_map_data *)malloc(sizeof(t_map_data));
			_guard_data(data);
			data->max_width = 0;
			if (_read_file(argv[i], data) == 0)
				write(2, "map error\n", 10);
			if (i != argc - 1)
				write(1, "\n", 1);
			i++;
			_free_data(data);
		}
	}
	return (0);
}
