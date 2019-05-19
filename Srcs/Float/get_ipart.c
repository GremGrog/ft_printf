/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ipart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:47:05 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/18 17:42:18 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void    get_ipart()
{
    int i;

    i = 0;
    while (g_buffer->str[i] != '.' && g_buffer->str[i] != '\0')
        i++;
    if (g_buffer->str[i] != '.')
        g_buffer->str[i++] = '.';
    g_ipart = i - 1;
}