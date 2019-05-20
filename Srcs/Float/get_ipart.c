/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ipart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:47:05 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/20 16:45:04 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void	get_ipart(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(g_buffer->str[i] >= '0' && g_buffer->str[i] <= '9')
	&& g_buffer->str[i] != '-')
	{
		g_buffer->final[j++] = '0';
		while (g_buffer->str[i] != '\0')
			g_buffer->final[j++] = g_buffer->str[i++];
		ft_bzero(g_buffer->str, g_buffer->buff_size);
		ft_strcpy(g_buffer->str, g_buffer->final);
		ft_bzero(g_buffer->final, g_buffer->buff_size);
	}
	while (g_buffer->str[i] != '.' && g_buffer->str[i] != '\0')
		i++;
	if (g_buffer->str[i] != '.')
		g_buffer->str[i++] = '.';
	g_ipart = i - 1;
}
