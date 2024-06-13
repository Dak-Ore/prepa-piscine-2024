/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:58:17 by dak               #+#    #+#             */
/*   Updated: 2024/06/13 21:42:30 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ' || base[i] > '~')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_pos_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	isneg;
	int	res;
	int	bsize;

	bsize = base_len(base);
	isneg = 1;
	res = 0;
	if (bsize == 0)
		return (res);
	while (*str == ' ')
		str++;
	while (((*str == '-' || (*str >= '\t' && *str <= '\r')
				|| *str == '+') && res == 0)
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

char	*ft_putnbr_base(int nbr, char *base, int len)
{
	int		bsize;
	char	*res;
	int		isneg;

	isneg = 0;
	bsize = base_len(base);
	if (nbr < 0)
	{
		isneg = 1;
		nbr = -nbr;
	}
	res = (char *)malloc(sizeof(char) * (len + isneg + 1));
	res[len + isneg] = '\0';
	while (len--)
	{
		res[len + isneg] = base[nbr % bsize];
		nbr /= bsize;
	}
	if (isneg)
		res[0] = '-';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		int_value;
	char	*result;
	int		i;
	int		len;
	int		valuetemp;

	i = 1;
	if (base_len(base_from) < 2 || base_len(base_to) < 2)
		return (NULL);
	int_value = ft_atoi_base(nbr, base_from);
	len = 0;
	valuetemp = int_value;
	if (int_value < 0)
		valuetemp = -int_value;
	while (i < valuetemp)
	{
		i = i * base_len(base_to);
		len++;
	}
	result = ft_putnbr_base(int_value, base_to, len);
	return (result);
}
