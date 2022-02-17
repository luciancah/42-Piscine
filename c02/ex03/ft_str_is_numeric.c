/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:40:23 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/07 10:58:44 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	flag;

	flag = 0;
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			flag = 1;
		else
			return (0);
		str++;
	}
	return (flag);
}
