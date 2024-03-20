/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:00:26 by dak               #+#    #+#             */
/*   Updated: 2024/03/20 20:14:11 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
