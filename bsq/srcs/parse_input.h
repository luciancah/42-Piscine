/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:20:39 by siseo             #+#    #+#             */
/*   Updated: 2022/02/24 10:48:24 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INPUT_H
# define PARSE_INPUT_H

# include <stdlib.h>
# include "data.h"

int		_atoi(char *str, int n);
int		_is_printable(char c);
int		_valid_map(char *map, t_map_data *data);
void	_guard_all(char *buf, t_map_data *data);
void	solve(t_map_data *data);

#endif
