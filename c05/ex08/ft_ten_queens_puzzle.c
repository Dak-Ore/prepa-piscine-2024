/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:35:58 by dak               #+#    #+#             */
/*   Updated: 2024/04/07 15:31:05 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_diago(int **board, int x, int y)
{
	int	i;

	if (x > y)
		i = 0 - y;
	else
		i = 0 - x;
	while (x + i < 10 && y + i < 10)
	{
		if (board[x + i][y + i] == 1 && i != 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_create_board(int **board)
{

}

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}
