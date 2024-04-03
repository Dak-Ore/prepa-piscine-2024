/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:12:08 by dak               #+#    #+#             */
/*   Updated: 2024/03/27 16:42:13 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlens(int size, char **strs, char *sep)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (nb < size)
	{
		i += ft_strlen(strs[nb]);
		if (nb != (size - 1))
			i += ft_strlen(sep);
		nb++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		nb;

	str = malloc(sizeof(char) * (ft_strlens(size, strs, sep)));
	if (str == NULL)
		return (NULL);
	nb = -1;
	j = 0;
	while (++nb < size)
	{
		i = 0;
		while (strs[nb][i])
			str[j++] = strs[nb][i++];
		i = 0;
		while (sep[i] && nb != (size - 1))
			str[j++] = sep[i++];
	}
	str[j] = '\0';
	return (str);
}
