/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:02:37 by dak               #+#    #+#             */
/*   Updated: 2024/02/22 13:03:37 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	res;
	char	tab[11];
	int		size;

	res = nb;
	if (res < 0)
	{
		write(1, "-", 1);
		res = -res;
	}
	size = 0;
	while (res != 0)
	{
		tab[size] = '0' + (res % 10);
		res /= 10;
		size++;
	}
	while (size >= 0)
	{
		write(1, &tab[size], 1);
		size--;
	}
}

/*
int		main(void)
{
	ft_putnbr(-25532340);
}
*/