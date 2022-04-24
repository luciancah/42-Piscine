/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:48:49 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/20 13:15:20 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*_strdup(char *src)
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

int	_wc(char *str, int len)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 1;
	if (str[0] == '\0')
		flag = 0;
	while (i < len)
	{
		if (str[i] == '\0')
			flag = 1;
		else
		{
			if (flag == 1)
				count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

char	*_editstr(char *str, char *charset, int len)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	temp = _strdup(str);
	while (i < _strlen(charset))
	{
		j = 0;
		while (j < len)
		{
			if (temp[j] == charset[i])
				temp[j] = '\0';
			j++;
		}
		i++;
	}
	return (temp);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		index;
	int		str_len;
	char	*newstr;
	char	**answer;

	str_len = _strlen(str);
	newstr = _editstr(str, charset, str_len);
	answer = (char **)malloc(sizeof(char *) * (_wc(newstr, str_len) + 1));
	if (!answer)
		return (0);
	i = 0;
	index = 0;
	while (i < str_len)
	{
		if (newstr[i] == '\0' || _strlen(newstr + i) == 0)
		{
			i++;
			continue ;
		}
		answer[index++] = _strdup(newstr + i);
		i += _strlen(newstr + i);
	}
	answer[index] = 0;
	return (answer);
}
