/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:49:47 by qmebble           #+#    #+#             */
/*   Updated: 2018/12/04 19:53:51 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*a;
	unsigned int	len;

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
		a[len] = f(len, s[len]);
		len++;
	}
	a[len] = '\0';
	return (a);
}
