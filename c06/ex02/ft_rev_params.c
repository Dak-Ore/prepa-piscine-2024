/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:47:17 by dak               #+#    #+#             */
/*   Updated: 2024/03/10 21:17:57 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*param;

	if (argc < 2)
		return (1);
	while (argc - 1 > 0)
	{
		param = argv[argc - 1];
		while (*param)
		{
			write(1, &*param, 1);
			param++;
		}
		write(1, "\n", 1);
		argc--;
	}
}