/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:32:49 by dak               #+#    #+#             */
/*   Updated: 2024/03/04 15:25:36 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		check;

	if (!*to_find)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			check = 0;
			while (to_find[i])
			{
				if (to_find[i] != str[i])
					check = 1;
				i++;
			}
			if (check == 0)
				return (str);
		}
		str++;
	}
	return (0);
}
