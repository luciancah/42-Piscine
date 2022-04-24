/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:07:37 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/13 19:22:10 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign_flag;
	int	answer;

	answer = 0;
	sign_flag = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign_flag *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		answer *= 10;
		answer += *str - '0';
		str++;
	}
	return (answer * sign_flag);
}
