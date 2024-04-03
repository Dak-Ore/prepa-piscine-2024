/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:48:09 by dak               #+#    #+#             */
/*   Updated: 2024/04/03 13:12:22 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_cp(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * ft_len(str) + 1);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*res;
	int			i;

	i = 0;
	res = malloc(sizeof(t_stock_str) * ac + 1);
	while (i < ac)
	{
		res[i].size = ft_len(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_cp(av[i]);
		i++;
	}
	res[i].size = 0;
	res[i].str = 0;
	res[i].copy = 0;
	return (res);
}
