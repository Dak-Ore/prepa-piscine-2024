/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dak <dak@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:20:23 by dak               #+#    #+#             */
/*   Updated: 2024/02/23 20:23:14 by dak              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c) {
    write(1, &c, 1);
}

void	ft_print_combn_recursive(int n, int start, int current, int combination) {
	int		len;
	char	buffer[10];

    if	(current == n)
	{
		len = 0;
		while (combination > 0)
		{
			buffer[len++] = combination % 10 + '0';
			combination /= 10;
		}
        for (int i = len - 1; i >= 0; --i) 
		{
            ft_putchar(buffer[i]);
        }
        
    } else {
		if (start <= 9) {
			ft_print_combn_recursive(n, start + 1, current + 1, combination * 10 + start);
			ft_print_combn_recursive(n, start + 1, current, combination);
		}
	}

}

void ft_print_combn(int n) {
    ft_print_combn_recursive(n, 0, 0, 0);
}

int main() {
    int n = 3; // Change this to the desired number of digits
    ft_print_combn(n);
    return 0;
}