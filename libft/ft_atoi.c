/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:17:30 by qmebble           #+#    #+#             */
/*   Updated: 2018/12/04 17:29:18 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	prov(const char *str, int i, int flag)
{
	unsigned long long n;

	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		n += str[i] - '0';
		if (n > 9223372036854775807)
		{
			if (flag == -1)
				return (0);
			return (-1);
		}
		i++;
	}
	return (n * flag);
}

int			ft_atoi(const char *str)
{
	int					i;
	int					flag;

	i = 0;
	flag = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	return (prov(str, i, flag));
}
