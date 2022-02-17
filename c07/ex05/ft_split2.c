/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:20:52 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/17 21:02:35 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

int	_next_word_len(char *str, char *charset)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while(str)
	{
		j = 0;
		while(charset[j])
		{
			j++;
			if(*str == charset[j])
				return (count);
		}
		str++;
		count++;
	}
	return (count);
}

int	_word_count(char *str, char *charset)
{
	int count;

	count = 0;
	while (*str)
	{
		while(_next_word_len(str, charset) == 0)
			str++;
		count++;
		str = str + _next_word_len(str, charset) + 1;
	}
	return (count);
}

char	*_init_word(char *str, int len)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = (char *)malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		word_count;
	int		word_len;
	int		i;

	i = 0;
	word_count = _word_count(str, charset);
	split = (char **)malloc((word_count + 1) * sizeof(char *));
	while (i < word_count)
	{
		word_len = _next_word_len(str, charset);
		while (_next_word_len(str, charset) == 0)
			str++;
		split[i] = _init_word(str, word_len);
		i++;
		str = str + word_len + 1;
	}
	split[i] = 0;
	return (split);
}

int	main()
{
	printf("----ex05----\n");
		char **str_arr;
		int i;
		str_arr = ft_split("Hello World Cat\\Dog\\Pizza School","\\");
		for(i=0;str_arr[i] != 0; i++)
			printf("%s\n",str_arr[i]);
		for(i=0;str_arr[i] != 0; i++)
			free(str_arr[i]);
		free(str_arr);
		str_arr = ft_split("Hello World CatDogPizza School","World");
		for(i=0;str_arr[i] != 0; i++)
			printf("%s\n",str_arr[i]);
		for(i=0;str_arr[i] != 0; i++)
			free(str_arr[i]);
		free(str_arr);
}
