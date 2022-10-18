/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:52:25 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/17 19:05:02 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_NULL '\0'

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str != FT_NULL)
	{
		length += 1;
		str += 1;
	}
	return (length);
}
