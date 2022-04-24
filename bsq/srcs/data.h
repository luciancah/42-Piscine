/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:16:37 by siseo             #+#    #+#             */
/*   Updated: 2022/02/24 10:45:16 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map_data
{
	int		**max_width;
	char	empty;
	char	obstacle;
	char	fill;
	int		x;
	int		y;
}	t_map_data;

#endif
