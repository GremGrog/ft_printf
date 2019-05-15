/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:27:58 by qmebble           #+#    #+#             */
/*   Updated: 2018/12/05 21:33:33 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countl(const char *s, int i, char c)
{
	int len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char	*split(const char *s, int i, char c)
{
	char	*a;
	int		j;

	j = 0;
	i--;
	a = (char *)malloc(sizeof(char) * countl(s, i + 1, c));
	while (s[++i] && s[i] != c)
	{
		a[j] = s[i];
		j++;
	}
	a[j] = '\0';
	return (a);
}

static int	couw(const char *s, char c)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] == c && s[i - 1] != c)
			count++;
	return (count + 1);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**a;

	if (s == NULL || !(a = (char **)malloc(sizeof(char *) * (couw(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
		if ((s[i] != c && s[i - 1] == c) || (s[i] != c && i == 0))
		{
			a[j] = split(s, i, c);
			j++;
		}
	a[j] = NULL;
	i = 0;
	return (a);
}
