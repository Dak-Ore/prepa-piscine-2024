/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:10:08 by dak               #+#    #+#             */
/*   Updated: 2024/04/09 18:52:10 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str, int size)
{
	int	i;

	i = 0;
	while (i < 16 && i < size)
	{
		if (str[i] < ' ' || str[i] > '~')
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_addr(long addr)
{
	long	i;
	char	*tab;
	char	res[17];

	tab = "0123456789abcdef";
	res[16] = '0';
	i = 0;
	while (i < 16)
	{
		if (addr > 0)
		{
			res[15 - i] = tab[addr % 16];
			addr /= 16;
		}
		else
			res[15 - i] = '0';
		i++;
	}
	write(1, res, 16);
	write(1, ": ", 2);
}

void	ft_print_char_to_hexa(unsigned char c)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (c / 16 > 0)
	{
		write(1, &tab[c / 16], 1);
		write(1, &tab[c % 16], 1);
	}
	else
	{
		write(1, "0", 1);
		write(1, &tab[c], 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*str;

	if (size > 0)
	{
		i = 0;
		str = addr;
		ft_print_addr((long) addr);
		while (i < size && i < 16)
		{
			ft_print_char_to_hexa(str[i]);
			if (++i % 2 == 0)
				write(1, " ", 1);
		}
		while (i < 16)
		{
			write(1, "  ", 2);
			if (++i % 2 == 0)
				write(1, " ", 1);
		}
		ft_putstr(str, size);
		if (size >= 16)
			ft_print_memory(&str[i], size - 16);
	}
	return (addr);
}
