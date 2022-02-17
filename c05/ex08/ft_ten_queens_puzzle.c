/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:34:27 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/14 15:52:29 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_putint(int i)
{
	char	c;

	c = i + '0';
	write(1, &c, 1);
}

void	_print_queens(int *board)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		_putint(board[i]);
		i++;
	}
	write(1, "\n", 1);
}

int	_validate_queens(int *board, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == board[col])
			return (0);
		else if (board[col] - board[i] == col - i)
			return (0);
		else if (board[i] - board[col] == col - i)
			return (0);
		i++;
	}
	return (1);
}

void	_set_queens(int *board, int col, int *count)
{
	board[col] = 0;
	while (board[col] < 10)
	{
		if (_validate_queens(board, col))
		{
			if (col == 9)
			{
				_print_queens(board);
				(*count)++;
			}
			else
				_set_queens(board, col + 1, count);
		}
		board[col]++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	_set_queens(board, 0, &count);
	return (count);
}
