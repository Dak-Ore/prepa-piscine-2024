/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:10:51 by dak               #+#    #+#             */
/*   Updated: 2024/02/26 13:15:45 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putout(int nb, int *tab, int is_1st)
{
	int	i;

	if (is_1st == 0)
	{
		write(1, ", ", 2);
	}
	i = 0;
	while (i < nb)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
}

void	ft_increment_combn(int nb, int *tab)
{
	int	i;
	int	limit;

	i = nb - 1;
	limit = 9;
	while (tab[i] == limit)
	{
		i--;
		limit--;
	}
	tab[i] += 1;
	while (i < nb)
	{
		tab[i + 1] = tab[i] + 1;
		i++;
	}
}

void	ft_print_combn(int nb)
{
	int	tab[10];
	int	i;

	i = 0;
	while (i < nb)
	{
		tab[i] = i;
		i++;
	}
	ft_putout(nb, tab, 1);
	while (tab[0] != 10 - nb || tab[nb - 1] != 9)
	{
		if (tab[nb - 1] != 9)
		{
			tab[nb - 1]++;
		}
		else
		{
			ft_increment_combn(nb, tab);
		}
		ft_putout(nb, tab, 0);
	}
}

/*
int	main(void)
{
	ft_print_combn(4);
}
*/
