/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 09:34:46 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/05 11:28:35 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

typedef struct s_square
{
	int	x;
	int	y;
}	t_square;

t_square	init(int w, int h)
{
	t_square	res;

	res.x = 0;
	res.y = 0;

	if(w <= 0 || h <= 0) {
		res.x = w;
		res.y = h;
	}
	return (res);
}

void	rush(int w, int h)
{
	t_square	s;

	s = init(w, h);
	while (s.y < h)
	{
		s.x = 0;
		while (s.x < w)
		{
			if (s.y == 0 && s.x == 0)
				ft_putchar('o');
			else if (s.y == h - 1 && s.x == w - 1)
				ft_putchar('o');
			else if ((s.y == h - 1 && s.x == 0) || (s.y == 0 && s.x == w - 1))
				ft_putchar('o');
			else if (s.y == 0 || s.y == h - 1)
				ft_putchar('-');
			else if (s.x == 0 || s.x == w - 1)
				ft_putchar('|');
			else
				ft_putchar(' ');

			s.x++;
		}
		ft_putchar('\n');
		s.y++;
	}
}
