/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:18:07 by siseo             #+#    #+#             */
/*   Updated: 2022/02/24 10:19:57 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include "data.h"

int		_read_stdin(t_map_data *data);
int		_read_file(char *file_name, t_map_data *data);
void	_guard_data(t_map_data *data);
void	_free_data(t_map_data *data);

#endif