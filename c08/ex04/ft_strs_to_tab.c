/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:03:07 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/19 20:18:19 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;
	int		str_len;

	i = 0;
	str_len = _strlen(src);
	dup = (char *)malloc((str_len + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*arr;

	i = 0;
	arr = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!arr)
		return (0);
	while (i < ac)
	{
		arr[i].size = _strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].str = 0;
	return (arr);
}
