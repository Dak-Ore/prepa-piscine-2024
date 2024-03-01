/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:19:49 by dak               #+#    #+#             */
/*   Updated: 2024/02/29 23:23:03 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_lower_letter(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_lower_letter(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
