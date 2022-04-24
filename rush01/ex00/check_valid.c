/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:29:57 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/13 21:34:10 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	col_up(int (*board)[4], int *data)
{
	int	i;
	int	j;
	int	count;
	int	line_max;

	i = 0;
	while (i < 4)
	{
		count = 0;
		line_max = 0;
		j = 0;
		while (j < 4)
		{
			if (line_max < board[j][i])
			{
				line_max = board[j][i];
				count++;
			}
			j++;
		}
		if (count != data[i])
			return (0);
		i++;
	}
	return (1);
}

int	col_down(int (*board)[4], int *data)
{
	int	i;
	int	j;
	int	count;
	int	line_max;

	i = 0;
	while (i < 4)
	{
		count = 0;
		line_max = 0;
		j = 0;
		while (j < 4)
		{
			if (line_max < board[3 - j][i])
			{
				line_max = board[3 - j][i];
				count++;
			}
			j++;
		}
		if (count != data[i + 4])
			return (0);
		i++;
	}
	return (1);
}

int	row_left(int (*board)[4], int *data)
{
	int	i;
	int	j;
	int	count;
	int	line_max;

	i = 0;
	while (i < 4)
	{
		count = 0;
		line_max = 0;
		j = 0;
		while (j < 4)
		{
			if (line_max < board[i][j])
			{
				line_max = board[i][j];
				count++;
			}
			j++;
		}
		if (count != data[i + 8])
			return (0);
		i++;
	}
	return (1);
}

int	row_right(int (*board)[4], int *data)
{
	int	i;
	int	j;
	int	count;
	int	line_max;

	i = 0;
	while (i < 4)
	{
		count = 0;
		line_max = 0;
		j = 0;
		while (j < 4)
		{
			if (line_max < board[i][3 - j])
			{
				line_max = board[i][3 - j];
				count++;
			}
			j++;
		}
		if (count != data[i + 12])
			return (0);
		i++;
	}
	return (1);
}

int	is_valid(int (*board)[4], int *data)
{
	if (col_up(board, data) == 0)
		return (0);
	if (col_down(board, data) == 0)
		return (0);
	if (row_left(board, data) == 0)
		return (0);
	if (row_right(board, data) == 0)
		return (0);
	return (1);
}
