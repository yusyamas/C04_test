/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:49:34 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/17 20:18:11 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_digit(unsigned int n)
{
	unsigned int	next_nbr;
	unsigned int	current_digit;

	if (n == 0)
	{
		return ;
	}
	next_nbr = n / 10;
	current_digit = n % 10;
	ft_print_digit(next_nbr);
	ft_putchar((char)('0' + current_digit));
	return ;
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb == 0)
	{
		ft_putchar('0');
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb ^= -1;
		nb += 1;
	}
	n = (unsigned int)(nb);
	ft_print_digit(n);
}
