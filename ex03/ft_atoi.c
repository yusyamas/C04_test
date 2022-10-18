/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:20:27 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/17 22:16:31 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_isspace(char *c)
{
	while ((9 <= *c && *c <= 13) || *c == ' ')
	{
		c += 1;
	}
	return (c);
}

char	*ft_count_pm(char *c, int *sign)
{
	while (*c == '+' || *c == '-')
	{
		if (*c == '-')
			*sign += 1;
		c += 1;
	}
	return (c);
}

char	*ft_atoi_decide(char *c, int *ret)
{
	int	digit_number;

	while ('0' <= *c && *c <= '9')
	{
		*ret *= 10;
		digit_number = *c - '0';
		*ret += digit_number;
		c += 1;
	}
	return (c);
}

int	ft_atoi(char *str)
{
	int		ret;
	int		sign;
	char	*s;

	ret = 0;
	sign = 0;
	s = str;
	s = ft_isspace(s);
	s = ft_count_pm(s, &sign);
	s = ft_atoi_decide(s, &ret);
	if (sign % 2 == 1)
	{
		ret *= -1;
	}
	return (ret);
}
