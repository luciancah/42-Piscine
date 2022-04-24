/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:04:59 by hyeonjuk          #+#    #+#             */
/*   Updated: 2022/02/13 21:34:24 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check(int argc, char **argv, int *data);
int		is_valid(int (*board)[4], int *data);

int	is_duplicate(int (*board)[4], int row, int column, int num)
{
	int	i;

	i = 0;
	while (i < column)
	{
		if (board[row][i] == num)
			return (1);
		i++;
	}
	i = 0;
	while (i < row)
	{
		if (board[i][column] == num)
			return (1);
		i++;
	}
	return (0);
}

int	set_num(int (*board)[4], int row, int column, int *data)
{
	int	num;

	if (row == 4)
	{
		if (is_valid(board, data))
			return (1);
		else if (row == 4)
			return (0);
	}
	if (column == 4)
		return (set_num(board, row + 1, 0, data));
	num = 1;
	while (num < 5)
	{
		if (is_duplicate(board, row, column, num) == 1)
		{
			num++;
			continue ;
		}
		board[row][column] = num;
		if (set_num(board, row, column + 1, data))
			return (1);
		num++;
	}
	return (0);
}

void	print(int (*board)[4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			board[i][j] += '0';
			write(1, &board[i][j], 1);
			if (j == 3)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	data[16];
	int	board[4][4];
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			board[i][j] = 0;
	}
	if (check(argc, argv, data))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (set_num(board, 0, 0, data))
	{
		print(board);
	}
	else
		write(1, "Error\n", 6);
}
