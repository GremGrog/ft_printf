/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:38:09 by qmebble           #+#    #+#             */
/*   Updated: 2018/11/29 16:32:51 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (s1[i])
		i++;
	while (s2[++j])
		s1[i + j] = s2[j];
	s1[i + j] = '\0';
	return (s1);
}
