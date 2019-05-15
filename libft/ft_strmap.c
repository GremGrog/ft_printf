/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:32:53 by qmebble           #+#    #+#             */
/*   Updated: 2018/12/04 19:54:18 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*a;
	int		len;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	len = 0;
	while (s[len])
	{
		a[len] = f(s[len]);
		len++;
	}
	a[len] = '\0';
	return (a);
}
