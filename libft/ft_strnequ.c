/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:55:46 by qmebble           #+#    #+#             */
/*   Updated: 2018/12/04 20:04:15 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t len)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (len == 0)
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < len - 1)
		i++;
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
