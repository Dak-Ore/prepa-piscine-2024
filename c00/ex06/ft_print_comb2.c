/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:56:31 by dak               #+#    #+#             */
/*   Updated: 2024/02/22 01:20:30 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_number(int number)
{
	char	number_tab[3];

	number_tab[0] = '0' + number / 10;
	number_tab[1] = '0' + number % 10;
	number_tab[2] = '\0';
	write(1, &number_tab, 2);
}

void	ft_print_comb2(void)
{
	int	n_left;
	int	n_right;

	n_left = 0;
	while (n_left <= 98)
	{
		n_right = n_left + 1;
		while (n_right <= 99)
		{
			write_number(n_left);
			write(1, " ", 1);
			write_number(n_right);
			if (!(n_left == 98 && n_right == 99))
				write(1, ", ", 2);
			n_right++;
		}
		n_left++;
	}
	write(1, "\n", 1);
}

/*
int		main(void)
{
	ft_print_comb2();
}
*/
