/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:07:10 by qmebble           #+#    #+#             */
/*   Updated: 2018/11/30 21:56:08 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		t;

	i = -1;
	j = -1;
	if (s1 == s2)
		return ((char *)s1);
	if (s2[++i] == '\0')
		return ((char *)s1);
	i = -1;
	while (s1[++i])
	{
		t = i;
		while (s2[++j] == s1[i] && s2[j] != '\0' && s1[j] != '\0')
			i++;
		if (s2[j] == '\0')
			return ((char *)(&s1[t]));
		j = -1;
		i = t;
	}
	return (NULL);
}
