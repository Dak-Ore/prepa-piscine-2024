/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:53:09 by dak               #+#    #+#             */
/*   Updated: 2024/02/20 15:57:24 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write(1, 'N', 1);
	}
	else
	{
		write(1, 'P', 1);
	}
}
/*
int		main(void)
{
	ft_print_reverse_alphabet();
}
*/