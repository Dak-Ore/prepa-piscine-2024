/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:04:03 by dak               #+#    #+#             */
/*   Updated: 2024/02/21 11:53:46 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int	n_left;
	int	n_mid;
	int	n_right;

	n_left = '0';
	while (n_left <= '7')
	{
		n_mid = n_left + 1;
		while (n_mid <= '8')
		{
			n_right = n_mid + 1;
			while (n_right <= '9')
			{
				write(1, &n_left, 1);
				write(1, &n_mid, 1);
				write(1, &n_right, 1);
				if (!(n_left == '7' && n_mid == '8' && n_right == '9'))
					write(1, ", ", 2);
				n_right++;
			}
			n_mid++;
		}
		n_left++;
	}
	write(1, "\n", 2);
}
/*
int		main(void)
{
	ft_print_comb();
}
*/