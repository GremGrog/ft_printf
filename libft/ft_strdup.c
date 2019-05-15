/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:11:13 by qmebble           #+#    #+#             */
/*   Updated: 2018/11/30 21:23:08 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = -1;
	while (s1[i] != '\0')
		i++;
	c = (char*)malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	while (s1[++j] != '\0')
		c[j] = s1[j];
	c[j] = '\0';
	return (c);
}
