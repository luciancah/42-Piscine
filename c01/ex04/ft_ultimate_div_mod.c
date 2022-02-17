/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:26:12 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/06 10:45:54 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div_temp;
	int	mod_temp;

	div_temp = *a / *b;
	mod_temp = *a % *b;
	*a = div_temp;
	*b = mod_temp;
}
