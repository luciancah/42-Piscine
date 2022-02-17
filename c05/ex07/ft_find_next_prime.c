/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:06:02 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/14 19:22:44 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

// int	ft_is_prime(int nb)
// {
// 	long long	i;
// 	int			flag;

// 	i = 2;
// 	flag = 1;
// 	if (nb < 2)
// 		return (0);
// 	while (i * i <= nb)
// 	{
// 		if (nb % i == 0)
// 			flag = 0;
// 		i++;
// 	}
// 	return (flag);
// }

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
