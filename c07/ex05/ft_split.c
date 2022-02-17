/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:48:49 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/17 17:20:46 by jinhlee          ###   ########seoul.kr  */
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

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;
	int		str_len;

	i = 0;
	str_len = _strlen(src);
	dup = (char *)malloc((str_len + 1) * sizeof(char));
	while (i < str_len)
	{
		dup[i] = src[i];
		i++;
	}
	src[i] = '\0';
	return (dup);
}

int	_strcnt(char *str, char *charset)
{
	int	str_cnt;
	int	search_cnt;
	int	i;
	int	j;

	str_cnt = 0;
	search_cnt = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		search_cnt++;
		while (charset[j])
		{
			if(search_cnt > 1)
				if (str[i] == charset[j])
				{
					str_cnt++;
					search_cnt = 0;
					break;
				}
			j++;
		}
		i++;
	}
	return (str_cnt);
}

void _strinit(char *str_src, char *str_dest, char *charset, int index)
{
	int	str_cnt;
	int	search_cnt;
	int	i;
	int	j;

	str_cnt = 0;
	search_cnt = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		search_cnt++;
		while (charset[j])
		{
			if(search_cnt > 1)
				if (str[i] == charset[j])
				{

					search_cnt = 0;
					break;
				}
			j++;
		}
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		str_count;
	int		i;
	char	**split;

	str_count = _strcnt(str, charset);
	split = (char **)malloc(str_count * sizeof(char *));
	if (!split)
		return (0);
	i = 0;
	while (i < str_count)
	{
		_strinit(str, charset, i);
	}


}

int	main(int argc, char **argv)
{
	int		index;
	char	**split;
	(void)	argc;
	split = ft_split(argv[1], argv[2]);
	index = 0;
	while (split[index])
	{
		printf("%s\n", split[index]);
		index++;
	}
}
