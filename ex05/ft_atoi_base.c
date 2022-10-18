/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:58:53 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/18 13:07:34 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define FT_NULL '\0'

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

char	*ft_atoi_prefix(char *c, int *sign)
{
	while ((9 <= *c && *c <= 13) || *c == ' ')
	{
		c += 1;
	}
	while (*c == '+' || *c == '-')
	{
		if (*c == '-')
			*sign += 1;
		c += 1;
	}
	return (c);
}

char	*ft_atoi_decide(char *c, int *ret, unsigned int n, char *base)
{
	unsigned int	i;
	int				is_end;

	is_end = 1;
	while (is_end)
	{
		i = 0;
		*ret *= n;
		while (i < n)
		{
			if (base[i] == *c)
			{
				*ret += i;
				break ;
			}
			if (i == n - 1 && base[i] != *c)
				is_end = 0;
			i += 1;
		}
		c += 1;
	}
	*ret /= n;
	return (c);
}

int	base_num_decide(char *base)
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
	while (*c != FT_NULL)
	{
		if (*c == '+' || *c == '-' || *c == ' ')
			return (0);
		cnt[(int)*c] += 1;
		if (cnt[(int)*c] >= 2)
			return (0);
		c += 1;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	base_num;
	int				ret;
	int				sign;
	char			*s;

	ret = 0;
	sign = 0;
	base_num = 0;
	base_num = ft_strlen(base);
	if (base_num > 1 && base_num_decide(base))
	{
		s = str;
		s = ft_atoi_prefix(s, &sign);
		s = ft_atoi_decide(s, &ret, base_num, base);
	}
	if (sign % 2 == 1)
	{
		ret *= -1;
	}
	return (ret);
}
