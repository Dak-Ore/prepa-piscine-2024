/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:56:36 by dak               #+#    #+#             */
/*   Updated: 2024/03/01 16:37:07 by dak              ###   ########.fr       */
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

void	ft_print_char_to_hexa(char c)
{
	char	*tab;
	int		i;
	int		first;

	i = 0;
	first = 0;
	tab = "0123456789abcdef";
	while (c > 16)
	{
		first++;
		c = c - 16;
	}
	ft_putchar(first + 48);
	i = c;
	ft_putchar(tab[i]);
}

void	ft_putstr_non_printable(char *str)
{
	int        i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_char_is_printable(str[i])))
		{
			ft_putchar(92);
			ft_print_char_to_hexa(str[i]);
		}
		else if (ft_char_is_printable(str[i]))
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}