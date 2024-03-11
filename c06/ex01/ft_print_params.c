/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:47:17 by dak               #+#    #+#             */
/*   Updated: 2024/03/10 21:12:29 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	*param;

	i = 1;
	if (argc < 2)
		return (1);
	while (i < argc)
	{
		param = argv[i];
		while (*param)
		{
			write(1, &*param, 1);
			param++;
		}
		write(1, "\n", 1);
		i++;
	}
}