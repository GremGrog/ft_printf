/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:20:32 by qmebble           #+#    #+#             */
/*   Updated: 2018/11/30 21:56:47 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	t;

	i = -1;
	j = 0;
	if (s1 == s2)
		return ((char *)s1);
	if (s2[++i] == '\0')
		return ((char *)s1);
	i = -1;
	while (s1[++i] && i < len)
	{
		t = i;
		while (s2[j] == s1[i] && s1[i] && s2[j] && i < len)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)(&s1[t]));
		j = 0;
		i = t;
	}
	return (NULL);
}
