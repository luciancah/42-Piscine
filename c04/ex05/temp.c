int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

int	_validate_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (0);
		else if (base[i] == '\n' || base[i] == '\t' || \
			base[i] == '\v' || base[i] == '\r')
			return (0);
	}
	i = -1;
	while (base[++i] != '\0')
	{
		j = i;
		while (base[++j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

long long	_get_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			base_n;
	int			is_positive;
	long long	answer;

	if (!_validate_base(base))
		return (0);
	base_n = ft_strlen(base);
	is_positive = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' \
		|| *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_positive *= -1;
		str++;
	}
	answer = 0;
	while (_get_base(*str, base) != -1)
	{
		answer *= base_n;
		answer += _get_base(*str, base);
		str++;
	}
	return (answer * is_positive);
}




int	ft_atoi(char *str)
{
	int	sign_flag;
	int	answer;

	answer = 0;
	sign_flag = 1;
	while (*str < '0' || *str > '9')
	{
		if (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
			|| *str == '\r' || *str == ' ' || *str == '+')
			str++;
		if (*str == '-')
		{
			sign_flag *= -1;
			str++;
		}
	}
	while (*str >= '0' && *str <= '9')
	{
		answer *= 10;
		answer += *str - '0';
		str++;
	}
	return (answer * sign_flag);
}
