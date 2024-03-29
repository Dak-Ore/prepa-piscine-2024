/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:02:37 by dak               #+#    #+#             */
/*   Updated: 2024/02/28 14:22:11 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	res;

	res = nb;
	if (res < 0)
	{
		ft_putchar('-');
		res = -res;
	}
	if (res < 10)
		ft_putchar('0' + res);
	if (res > 9)
	{
		ft_putnbr(res / 10);
		ft_putchar('0' + (res % 10));
	}
}

int		main(void)
{
	ft_putnbr(42);
}
*/