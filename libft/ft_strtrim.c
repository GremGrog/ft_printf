/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:18:45 by qmebble           #+#    #+#             */
/*   Updated: 2018/12/04 19:50:17 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static char	*prov(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char	*a;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	i = len(s);
	j = ft_strlen(s);
	if (j == i)
		return (prov());
	while (s[j] == '\t' || s[j] == '\n' || s[j] == ' ' || s[j] == '\0')
		j--;
	if (!(a = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	start = 0;
	while (i <= j)
	{
		a[start] = s[i];
		start++;
		i++;
	}
	a[start] = '\0';
	return (a);
}
