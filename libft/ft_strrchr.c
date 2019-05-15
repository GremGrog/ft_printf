/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:28:37 by qmebble           #+#    #+#             */
/*   Updated: 2018/11/30 22:07:08 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] == c)
			j = i;
	if (s[i] == c)
		return ((char *)&s[i]);
	if (j == 0 && s[j] != c)
		return (NULL);
	return ((char *)&s[j]);
}
