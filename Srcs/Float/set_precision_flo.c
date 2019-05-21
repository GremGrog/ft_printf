/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision_flo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:42 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/21 20:22:40 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

//void		round_up(t_pf *data, int i, int j)
//{
//	while (data->precision > 0)
//	{
//		g_buffer->final[j++] = g_buffer->str[i++];
//		if (g_buffer->str[i + 1] == '9')
//		{
//			if (g_buffer->str[i] == '9')
//				g_buffer->str[i] = '0';
//			else
//				g_buffer->str[i]++;
//		}
//		if (data->precision == 0 && g_buffer->str[i + 1] >= '5')
//			g_buffer->final[j] = g_buffer->str[i]++;
//		if (g_buffer->str[i] == '\0')
//		{
//			while (data->precision > 0)
//			{
//				g_buffer->final[j++] = '0';
//				data->precision--;
//			}
//		}
//		data->precision--;
//	}
//	g_buffer->str_len = j;
//}

void		round_up(t_pf *data, int i, int j)
{
	while (data->precision > 0)
	{
		g_buffer->final[j++] = g_buffer->str[i++];
		data->precision--;
	}
	i--;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size);
	while (g_buffer->str[i] != '.')
	{
		if (g_buffer->str[i] == '9')
		{
			g_buffer->str[i] = '0';
			if (g_buffer->str[i - 1] == '9')
				g_buffer->str[i - 1] = '0';
			else
				g_buffer->str[i - 1]++;
			i -= 2;
		}
		else
			i--;
	}
//	while (g_buffer->str[i] != '.')
//	{
//		if (g_buffer->str[i] == '9')
//		{
//			g_buffer->str[i] = '0';
//			g_buffer->str[i - 1]++;
//			i += 2;
//		}
//		else if (g_buffer->str[i] >= '5' && g_buffer->str[i] <= '9')
//		{
//			g_buffer->str[i]++;
//			i -= 1;
//		}
//		else
//			i--;
//	}
	g_buffer->str_len = j;
	ft_bzero(g_buffer->final, g_buffer->buff_size);
	ft_strcpy(g_buffer->final, g_buffer->str);
}

void		copy_flo(t_pf *data, int i, int j)
{
	while (data->precision > 0 && g_buffer->str[i] != '\0')
	{
		if (data->precision == 1 && (g_buffer->str[i + 1] != '\0'
			&& g_buffer->str[i] >= '5'))
		{
			if (g_buffer->str[i] == '9')
			{
				g_buffer->final[j - 1] = '1';
				g_buffer->str[i] = '0';
			}
			else
				g_buffer->final[j] = g_buffer->str[i]++;
			j++;
			i++;
		}
		g_buffer->final[j++] = g_buffer->str[i++];
		data->precision--;
	}
	if (g_buffer->str[i] == '\0')
	{
		while (data->precision > 0)
		{
			g_buffer->final[j++] = '0';
			data->precision--;
		}
	}
	g_buffer->str_len = j;
}

void		round_up_ipart(int i, int j, t_pf *data)
{
	g_buffer->final[j++] = g_buffer->str[i++];
	while (g_buffer->str[i - 1] != '.' )
	{
		g_buffer->final[j++] = g_buffer->str[i++];
		if (data->precision <= 0)
		{
			if (g_buffer->str[i] == '.' && (g_ipart > 1) &&
				(g_fpart >= 0.51 || g_fpart <= (-0.5) )&& g_buffer->str[i + 2] != '\0')
				g_buffer->final[j - 1]++;
			if (!CHECK_BIT(data->flags, 2))
			{
				if (g_buffer->str[i] == '.')
					break ;
			}
		}
	}
	check_and_add(g_buffer->str_len + data->precision);
	if (g_buffer->str[i + data->precision] >= '5')
		round_up(data, i, j);
	else
		copy_flo(data, i, j);
}

void		pres_for_null(int i, int j, t_pf *data)
{
	g_buffer->final[j++] = g_buffer->str[i++];
	while (data->precision >= 0)
	{
		g_buffer->final[j++] = g_buffer->str[i++];
		data->precision--;
		if (g_buffer->str[i + 1] == '9')
		{
			if (g_buffer->str[i] == '9')
				g_buffer->str[i] = '0';
			else
				g_buffer->str[i]++;
		}
		if (g_buffer->str[i] == '\0')
		{
			while (data->precision >= 0)
			{
				g_buffer->final[j++] = '0';
				data->precision--;
			}
		}
	}
	g_buffer->str_len = j;
}

void		set_precision_for_null(int i, int j, t_pf *data)
{
	if (g_buffer->str[i] == '-')
		data->precision++;
	if (data->precision > 0)
		return (pres_for_null(i, j, data));
	while (g_buffer->str[i])
	{
		g_buffer->final[j++] = g_buffer->str[i++];
		if (!(data->precision > 0))
		{
			if (g_buffer->str[i] == '.')
			{
				if (!CHECK_BIT(data->flags, 2))
					break;
				else
				{
					g_buffer->final[j++] = g_buffer->str[i];
					break;
				}
			}
		}
	}
	g_buffer->str_len = j;
}

void		set_precision_flo(t_pf *data)
{
	int		i;
	int		j;

	if (g_fpart == 1.0 / 0.0 || g_fpart == -1.0 / 0.0 || g_fpart != g_fpart || data->precision == 0)
		return ;
	i = 0;
	j = 0;
	if ((g_flo == 0 && !(CHECK_BIT(data->modificators, 0))) || (g_buffer->str[0] == '0'))
		set_precision_for_null(i, j, data);
	else
		round_up_ipart(i, j, data);
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size);
}
