/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:21:13 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/17 13:43:06 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int	_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

int	_len_total(int size, char **str)
{
	int	i;
	int	len_total;

	i = 0;
	len_total = 0;
	while (str[i] && i < size)
	{
		len_total += _strlen(str[i]);
		i++;
	}
	return (len_total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*answer;
	int		i;
	char	*cur;

	i = -1;
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	answer = (char *)malloc(((_len_total(size, strs) + _strlen(sep)
					* (size - 1)) + 1) * sizeof(char));
	if (!answer)
		return (0);
	cur = answer;
	while (++i < size)
	{
		_strcpy(cur, strs[i]);
		cur += _strlen(strs[i]);
		if (i < size - 1)
		{
			_strcpy(cur, sep);
			cur += _strlen(sep);
		}
	}
	*cur = '\0';
	return (answer);
}
