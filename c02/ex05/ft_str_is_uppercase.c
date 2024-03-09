/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:19:49 by dak               #+#    #+#             */
/*   Updated: 2024/02/29 23:33:35 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_letter(char c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_letter(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}