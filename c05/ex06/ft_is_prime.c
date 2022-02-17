/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:00:07 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/14 19:37:05 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	i;
	int			flag;

	i = 2;
	flag = 1;
	if (nb < 2)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			flag = 0;
		i++;
	}
	return (flag);
}
