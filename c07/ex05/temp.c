int	_word_count(char *str, int length)
{
	int	index;
	int	cnt;
	int	flag;

	index = -1;
	flag = (str[0] != '\0');
	cnt = 0;
	while (++index < length)
	{
		if (str[index] == '\0')
			flag = 1;
		else
		{
			if (flag == 1)
				cnt++;
			flag = 0;
		}
	}
	return (cnt);
}

char	*_init_str(char *str, char *charset, int length)
{
	int		i;
	int		j;
	char	*new_str;

	new_str = ft_strdup(str);
	i = -1;
	while (++i < ft_strlen(charset))
	{
		j = -1;
		while (++j < length)
		{
			if (new_str[j] == charset[i])
				new_str[j] = '\0';
		}
	}
	return (new_str);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		index;
	int		len;
	char	*_removed;
	char	**result;

	len = ft_strlen(str);
	_removed = _init_str(str, charset, len);
	result = (char **)malloc(sizeof(char *) * (_word_count(_removed, len) + 1));
	if (result == NULL)
		return (0);
	i = 0;
	index = 0;
	while (i < len)
	{
		if (_removed[i] == '\0' || !ft_strlen(_removed + i))
		{
			i++;
			continue ;
		}
		result[index++] = ft_strdup(_removed + i);
		i += ft_strlen(_removed + i);
	}
	result[index] = NULL;
	return (result);
}