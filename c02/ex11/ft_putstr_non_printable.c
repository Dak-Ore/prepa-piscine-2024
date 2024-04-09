/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:56:36 by dak               #+#    #+#             */
/*   Updated: 2024/04/09 18:33:57 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_char_is_printable(char c)
{
	if (c < ' ' || c > '~')
	{
		return (0);
	}
	return (1);
}

void	ft_print_char_to_hexa(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	if (c / 16 > 0)
	{
		ft_putchar(base[c / 16]);
		ft_putchar(base[c % 16]);
	}
	else
	{
		ft_putchar('0');
		ft_putchar(base[c]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_char_is_printable(str[i])))
		{
			ft_putchar(92);
			ft_print_char_to_hexa(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}
