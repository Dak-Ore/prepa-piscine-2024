/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:19:33 by dak               #+#    #+#             */
/*   Updated: 2024/04/02 20:20:00 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef int	t_bool;

# define TRUE	0
# define FALSE	1
# define SUCCESS	0
# define EVEN_MSG	"I have an even number of arguments.\n"
# define ODD_MSG	"I Have an odd number of arguments.\n"
# define EVEN(nb)	(nb%2)

#endif