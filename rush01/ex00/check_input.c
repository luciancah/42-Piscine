/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:29:42 by hyeonjuk          #+#    #+#             */
/*   Updated: 2022/02/13 21:33:52 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	check_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	check_str(char *str, int data[])
{
	int	word_count;
	int	i;

	i = 0;
	word_count = 0;
	while (word_count < 16 && str[i])
	{
		if (i % 2 == 1)
		{
			if (str[i] != ' ')
				return (1);
		}
		else
		{
			if (str[i] < '1' || str[i] > '4')
				return (1);
			data[word_count] = str[i] - '0';
			word_count++;
		}
		i++;
	}
	if (word_count == 16 && check_len(str) == 31)
		return (0);
	return (1);
}

int	check(int argc, char **argv, int *data)
{
	if (argc != 2)
		return (1);
	if (check_str(argv[1], data))
		return (1);
	return (0);
}
