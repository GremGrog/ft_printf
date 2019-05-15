/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:08:32 by qmebble           #+#    #+#             */
/*   Updated: 2018/12/04 17:31:24 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*a;

	i = -1;
	a = (char *)malloc(sizeof(char) * (size + 1));
	if (!a)
		return (NULL);
	ft_bzero(a, size + 1);
	return (a);
}
