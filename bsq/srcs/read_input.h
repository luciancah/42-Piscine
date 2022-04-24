/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:24:44 by siseo             #+#    #+#             */
/*   Updated: 2022/02/24 10:29:25 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_INPUT_H
# define READ_INPUT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "data.h"

# define BUF_SIZE 2147483647

int		_parse(char *buf, t_map_data *data);
char	*_strjoin(char *s1, char *s2);
void	_guard_buf(char *buf, t_map_data *data);
void	_guard_temp(char *temp, char *buf, t_map_data *data);

#endif