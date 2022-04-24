/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:37:39 by Seojun Yoo        #+#    #+#             */
/*   Updated: 2022/02/06 19:29:30 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	is_it_edge(int x, int y, int j, int i)
{
	if (j == 1 && i == 1)
		return (0);
	else if (j == x && i == 1)
		return (1);
	else if (j == 1 && i == y)
		return (1);
	else if (j == x && i == y)
		return (2);
	else if (j == 1 || j == x)
		return (3);
	else if (i == 1 || i == y)
		return (3);
	else
		return (4);
}

void	edge_modify(char *edges)
{
	edges[0] = '/';
	edges[1] = '\\';
	edges[2] = '/';
	edges[3] = '*';
	edges[4] = ' ';
}

void	rush(int x, int y)
{
	char	edges[5];
	int		i;
	int		j;

	edge_modify(edges);
	if (x < 1 || y < 1)
		return ;
	i = 1;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			ft_putchar(edges[is_it_edge(x, y, j, i)]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
