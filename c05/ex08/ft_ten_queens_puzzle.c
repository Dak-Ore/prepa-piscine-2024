/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:35:58 by dak               #+#    #+#             */
/*   Updated: 2024/06/10 22:13:19 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_placements(int board[10][10])
{
	int		row;
	int		col;
	char	c;

	row = -1;
	while (++row <= 9)
	{
		col = -1;
		while (++col <= 9)
		{
			if (board[row][col] == 1)
			{
				c = col + '0';
				write(1, &c, 1);
			}
		}
	}
}

void	ft_init_board(int board[10][10])
{
	int	row;
	int	col;

	row = -1;
	while (++row <= 9)
	{
		col = -1;
		while (++col <= 9)
			board[row][col] = 0;
	}
}

int	ft_can_place_queen(int board[10][10], int row, int col)
{
	int	i;

	if (col > 9)
		return (0);
	i = 1;
	while (i <= row)
	{
		if (board[row - i][col] == 1)
			return (0);
		if (col - i >= 0 && board[row - i][col - i] == 1)
			return (0);
		if (col + i <= 9 && board[row - i][col + i] == 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_place_queens(int board[10][10], int row, int *nbposs)
{
	int	col;

	if (row > 9)
	{
		ft_print_placements(board);
		write(1, "\n", 1);
		(*nbposs)++;
		return (0);
	}
	col = -1;
	while (++col <= 9)
	{
		if (ft_can_place_queen(board, row, col))
		{
			board[row][col] = 1;
			if (ft_place_queens(board, row + 1, nbposs))
				return (1);
			board[row][col] = 0;
		}
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	nbposs;

	nbposs = 0;
	ft_init_board(board);
	ft_place_queens(board, 0, &nbposs);
	return (nbposs);
}
