/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:00:26 by dak               #+#    #+#             */
/*   Updated: 2024/03/09 14:57:55 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	isneg;
	int	res;

	isneg = 1;
	res = 0;
	while (((*str == ' ' || *str == '-' || *str == '\n' || *str == '\t'
				|| *str == '\r' || *str == '\f' || *str == '+') && res == 0)
		|| (*str >= '0' && *str <= '9'))
	{
		if (*str == '-')
			isneg = -isneg;
		if (*str >= '0' && *str <= '9')
			res = (res * 10) + (*str - '0');
		str++;
	}
	if (isneg < 0)
		res = -res;
	return (res);
}
