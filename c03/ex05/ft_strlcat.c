/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:03:04 by dak               #+#    #+#             */
/*   Updated: 2024/04/07 00:22:50 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*dest != '\0' && i++ < size)
		dest++;
	while (*src != '\0' && i++ < size)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (i);
}
