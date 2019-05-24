/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision_flo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:42 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/24 22:26:08 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void		fill_zero(t_pf *data)
{
	int 	i;

	i = g_buffer->str_len;
	g_buffer->final[i++] = '.';
	while (data->precision > 0)
	{
		g_buffer->final[i++] = '0';
		data->precision--;
	}
	g_buffer->str_len = i;
}

void		add_one(t_pf *data, int i, int j)
{
	j = i;
	g_buffer->str_len = j;
	while (i > 0)
	{
		if (g_buffer->str[i] == '9')
			if (g_buffer->final[j] != '9')
				g_buffer->final[j]++;
			else
			{
				g_buffer->final[j] = '0';
				g_buffer->final[j - 1] == '9' ? g_buffer->final[j - 1] = '0'
						: g_buffer->final[j - 1]++;
				j--;
			}
		else if (g_buffer->str[i + 1] == '9')
		{
			if (g_buffer->final[j - 1] != '9')
				g_buffer->final[j - 1]++;
			if (g_buffer->final[j - 1] == '9')
				g_buffer->final[j - 1] = '0';
			j--;
		}
		j--;
		i--;
	}
	if (data->precision > 0)
		fill_zero(data);
}

void		add_extra(t_pf *data, int n)
{
	int 	i;
	int 	j;

	j = 0;
	i = 0;
	g_buffer->final[j++] = '1';
	while (j <= n)
	{
		if (g_buffer->str[i] == '.')
		{
			if (data->precision == -1)
				break;
			g_buffer->final[j++] = '.';
		}
		else
			g_buffer->final[j++] = '0';
		i++;
	}
	g_buffer->str_len = j;
}

void		round_up_nine(t_pf *data)
{
	int		i;
	int 	j;
	int 	n;
	int 	flag;

	n = g_buffer->str_len;
	i = 0;
	j = 0;
	flag = 0;
	while (g_buffer->str[i] != '.')
	{
		if (g_buffer->str[i] == '9')
			flag++;
		g_buffer->final[j++] = g_buffer->str[i++];
	}
	if (flag < i)
		add_one(data, i, j);
	if (flag == i)
		add_extra(data, n);
}

void		copy_flo(t_pf *data)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (g_buffer->str[i] != '.')
		g_buffer->final[j++] = g_buffer->str[i++];
	g_buffer->final[j++] = g_buffer->str[i++];
	while (data->precision > 0)
	{
		if (g_buffer->str[i] == '\0')
		{
			while (data->precision > 0)
			{
				g_buffer->final[j++] = '0';
				data->precision--;
			}
		}
		else
		{
			g_buffer->final[j++] = g_buffer->str[i++];
			data->precision--;
		}
	}
	if (g_buffer->str[i] >= '5')
		g_buffer->final[j - 1]++;
	g_buffer->str_len = j;
}

int 		to_ipart(int i)
{
	while (g_buffer->str[i] != '.')
		i++;
	return (i);
}

int		round_up(int i, int flag, int i_part)
{
	while (i > i_part)
	{
		if (g_buffer->str[i] == '9')
		{
			if (flag == 0 && g_buffer->str[i - 1] != '9')
				flag++;
			if (g_buffer->str[i - 1] != '.')
				g_buffer->str[i] = '0';
		}
		else if (flag != 0 && g_buffer->str[i] < '9')
		{
			g_buffer->str[i]++;
			i--;
			flag = 0;
		}
		else if (i == g_buffer->str_len - 1 && g_buffer->str[i + 1] >= '5' && g_buffer->str[i] < '9')
			g_buffer->str[i]++;
		if (g_buffer->str[i] == '.')
			;
		i--;
	}
	return (flag);
}

void		round_ipart(t_pf *data)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (g_buffer->str[i] != '.')
		g_buffer->final[j++] = g_buffer->str[i++];
	if (CHECK_BIT(data->flags, 2))
	{
		if (g_buffer->str[i + 1] >= '5')
			g_buffer->final[j - 1]++;
		g_buffer->final[j] = '.';
		g_buffer->str_len = j + 1;
	}
	else
	{
		if (g_buffer->str[i + 1] >= '5' && g_buffer->str[i + 2] != '\0')
		{
			if (g_buffer->final[j - 1] == '9')
				return (round_up_nine(data));
			g_buffer->final[j - 1]++;
		}
		if (g_buffer->str[i + 1] >= '5' && g_buffer->str[i + 2] == '\0')
		{
			if ((g_buffer->final[j - 1] - '0') % 2 == 1)
				g_buffer->final[j - 1]++;
		}
		g_buffer->str_len = j;
	}
}

void		round_up_flo(t_pf *data)
{
	int		i;
	int 	i_part;
	int 	flag;

	i = 0;
	i_part = to_ipart(i);
	flag = 0;
	if (data->precision > 0)
	{
		i = data->precision + i_part;
		g_buffer->str_len = i + 1;
		check_and_add(g_buffer->str_len + i);
		if (g_buffer->str[i] > '5' && g_buffer->str[i + 1] >= '5')
			flag = round_up(i, flag, i_part);
		else
		{
			copy_flo(data);
			return ;
		}
		if (flag == 1 && data->precision <= 5)
			round_up_nine(data);
		else
			ft_strcpy(g_buffer->final, g_buffer->str);
	}
	else
		round_ipart(data);

}

void		set_precision_flo(t_pf *data)
{
	if (g_fpart == 1.0 / 0.0 || g_fpart == -1.0 / 0.0 ||
		g_fpart != g_fpart || data->precision == 0)
		return ;
	round_up_flo(data);
	ft_bzero(g_buffer->str, g_buffer->buff_size);
	ft_memcpy(g_buffer->str, g_buffer->final, g_buffer->str_len);
	ft_bzero(g_buffer->final, g_buffer->buff_size);
}
