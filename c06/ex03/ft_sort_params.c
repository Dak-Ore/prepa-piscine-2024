/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:47:17 by dak               #+#    #+#             */
/*   Updated: 2024/03/10 23:21:36 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	if (s1[i] < s2[i])
		return (0);
	return (1);
}

void	sort_tab(char *tab[], int nb)
{
	char	*temp;
	int		i;
	int		j;

	i = 1;
	while (i < nb)
	{
		j = 1;
		while (j < nb - 1)
		{
			if (ft_strcmp(tab[j], tab[j + 1]))
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}


int	main(int argc, char *argv[])
{
	int		i;
	char	*param;

	i = 1;
	if (argc < 2)
		return (1);
	sort_tab(argv, argc);
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
