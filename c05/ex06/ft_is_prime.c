/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:57:43 by dak               #+#    #+#             */
/*   Updated: 2024/03/10 18:51:49 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while ((i * i) < nb)
		i++;
	return (i);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt;

	if (nb <= 1)
		return (0);
	i = 1;
	sqrt = ft_sqrt(nb);
	while (i <= sqrt)
	{
		i++;
		if (nb % i == 0 && i != nb)
			return (0);
	}
	return (1);
}

