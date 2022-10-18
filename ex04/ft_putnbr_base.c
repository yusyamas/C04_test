/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:27:52 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/18 13:16:28 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define FT_NULL '\0'

void	ft_print_digit(unsigned int n, unsigned int base_num, char *base)
{
	unsigned int	next_nbr;
	char			current_digit;

	if (n == 0)
	{
		return ;
	}
	next_nbr = n / base_num;
	current_digit = base[n % base_num];
	ft_print_digit(next_nbr, base_num, base);
	write(1, &current_digit, 1);
	return ;
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	length;
	char			*c;

	c = str;
	length = 0;
	while (*c != FT_NULL)
	{
		length += 1;
		c += 1;
	}
	return (length);
}

int	cnt_check(char *cnt)
{
	int	i;

	i = 0;
	while (i < 128)
	{
		if (cnt[i] >= 2)
			return (0);
		i += 1;
	}
	return (1);
}

int	base_num_decide(char *base, unsigned int *base_num)
{
	char	*c;
	int		i;
	char	cnt[128];

	c = base;
	i = 0;
	while (i < 128)
	{
		cnt[i] = 0;
		i += 1;
	}
	*base_num = ft_strlen(base);
	if (*base_num <= 1)
		return (0);
	while (*c != FT_NULL)
	{
		if (*c == '+' || *c == '-')
			return (0);
		cnt[(int)*c] += 1;
		c += 1;
	}
	if (cnt_check(cnt))
		return (1);
	else
		return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_num;
	unsigned int	n;
	char			c;

	base_num = 0;
	if (base_num_decide(base, &base_num))
	{
		if (nbr == 0)
		{
			c = base[0];
			write(1, &c, 1);
			return ;
		}
		else if (nbr < 0)
		{
			nbr *= -1;
			write(1, "-", 1);
		}
		n = (unsigned int)nbr;
		ft_print_digit(n, base_num, base);
	}
}
