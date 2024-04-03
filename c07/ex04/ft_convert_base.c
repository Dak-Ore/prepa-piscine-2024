/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:12:01 by dak               #+#    #+#             */
/*   Updated: 2024/03/26 17:19:52 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == '\n'
			|| base[i] == '\r' || base[i] == '\f' || base[i] == '+')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_pos_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c && base[i])
		i++;
	if (c != base[i])
		return (-1);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	isneg;
	int	res;
	int	bsize;

	bsize = base_len(base);
	isneg = 1;
	res = 0;
	while (((*str == ' ' || *str == '-' || *str == '\n' || *str == '\t'
				|| *str == '\r' || *str == '\f' || *str == '+') && res == 0)
		|| (ft_pos_base(*str, base) != -1 && *str))
	{
		if (*str == '-')
			isneg = -isneg;
		if (ft_pos_base(*str, base) != -1)
			res = (res * bsize) + ft_pos_base(*str, base);
		str++;
	}
	return (res * isneg);
}

void	ft_putnbr_base(int nb, char *base, char *dest)
{
	int		bsize;

	bsize = base_len(base);
	if (nb < 0)
	{
		dest[0] = '-';
		nb = -nb;
	}
	if (nb >= bsize)
		ft_putnbr_base(nb / bsize, base, dest);
	while ((ft_pos_base(*dest, base) != -1 || *dest == '-') && *dest)
		dest++;
	*dest = base[nb % bsize];
}

char	*ft_convert_base(char *nbr,	char *base_from, char *base_to)
{
	int		res;
	char	*dest;
	int		i;
	int		nb;
	char	len_base;

	len_base = base_len(base_to);
	if (base_len(base_from) < 2 || len_base < 2)
		return (NULL);
	res = ft_atoi_base(nbr, base_from);
	i = 1;
	nb = 1;
	while (i < res)
	{
		i = i * len_base;
		nb++;
	}
	dest = malloc(sizeof(char) * nb + 1);
	ft_putnbr_base(res, base_to, dest);
	return (dest);
}
