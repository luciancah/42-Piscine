/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:55:03 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/24 10:40:29 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	_strlcat(char *dest, char *src, int size)
{
	int	dest_len;
	int	i;

	dest_len = _strlen(dest);
	i = 0;
	if (size != 0 && dest_len < size)
	{
		while (src[i] != '\0' && i < size - dest_len - 1)
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = '\0';
		return (dest_len + _strlen(src));
	}
	return (size + _strlen(src));
}

int	_strlcpy(char *dest, char *src, int size)
{
	int	i;

	if (size != 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (_strlen(src));
}

char	*_strjoin(char *s1, char *s2)
{
	char	*res;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = _strlen(s1);
	s2_len = _strlen(s2);
	res = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!res)
		return (0);
	_strlcpy(res, s1, s1_len + 1);
	_strlcat(res, s2, s1_len + s2_len + 1);
	free(s1);
	free(s2);
	return (res);
}
