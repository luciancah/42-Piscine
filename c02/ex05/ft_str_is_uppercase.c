/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:59:50 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/07 11:01:14 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	flag;

	flag = 0;
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			flag = 1;
		else
			return (0);
		str++;
	}
	return (flag);
}
