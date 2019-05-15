/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:14:04 by qmebble           #+#    #+#             */
/*   Updated: 2018/12/04 19:52:03 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*a;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	a = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!a)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		a[i] = s1[i];
	while (s2[++j])
		a[i + j] = s2[j];
	a[i + j] = '\0';
	return (a);
}
