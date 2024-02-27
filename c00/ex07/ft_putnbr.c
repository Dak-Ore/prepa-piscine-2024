/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:02:37 by dak               #+#    #+#             */
/*   Updated: 2024/02/27 17:59:36 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printchar(char c)
{
	write(1, &c, 1);
}


void	ft_putnbr(int nb)
{
	long	res;
	char	tab[11];
	int		size;

	res = nb;
	if (res < 0)
	{
		ft_printchar('-');
		res = -res;
	}
	if (res == 0)
		ft_printchar('0');
	size = 0;
	while (res != 0)
	{
		tab[size] = '0' + (res % 10);
		res /= 10;
		size++;
	}
	while (size >= 0)
	{
		ft_printchar(tab[size]);
		size--;
	}
}

/*
int		main(void)
{
	ft_putnbr(2147483647);
}
*/