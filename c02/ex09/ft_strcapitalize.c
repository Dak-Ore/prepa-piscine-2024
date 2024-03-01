/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:19:49 by dak               #+#    #+#             */
/*   Updated: 2024/03/01 15:43:02 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		first;
	char	*lstr;

	first = 1;
	lstr = ft_strlowcase(str);
	while (*lstr)
	{
		if (first == 1 && *lstr >= 'a' && *lstr <= 'z')
			*lstr -= 32;
		first = 1;
		if ((*lstr >= 'A' && *lstr <= 'Z') || (*lstr >= 'a' && *lstr <= 'z')
			|| (*lstr >= '0' && *lstr <= '9'))
			first = 0;
		lstr++;
	}
	return (str);
}
