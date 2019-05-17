/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:21 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/17 17:35:21 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void					copy_long_double(char *z, int n, short sign)
{
	int					i;
	int					j;

	i = 0;
	j = 0;
	while (z[i] == 0)
	{
		i++;
		n--;
	}
	while (n-- > 0)
	{
		g_buffer->str[j++] = z[i++] + '0';
		if (n == 0)
			g_buffer->str[j++] = '.';
	}
	while (g_ipart > 0)
	{
		g_buffer->str[j++] = z[i++] + '0';
		g_ipart--;
	}
	if (sign == 1)
		g_buffer->str[j++] = '-';
	g_buffer->str_len = j;
	ft_strrev();
}

void					get_dfloat(unsigned long long m, short exp, short sign)
{
	char				*arr;
	char				*pow;
	char				*bow;
	char				*z;
	int					n;

	n = 63 - exp;
	arr = (char *)malloc(sizeof(char) * 200);
	pow = (char *)malloc(sizeof(char) * 200);
	bow = (char *)malloc(sizeof(char) * 200);
	z = (char *)malloc(sizeof(char) * 200);
	if (!arr || !pow || !bow || !z)
		return ;
	set_arr_to_null(bow);
	set_arr_to_null(pow);
	set_arr_to_null(z);
	set_arr_to_null(arr);
	pow = get_five_power(63, exp, pow, bow);
	number_to_arr(m, arr);
	multiplication_long(arr, pow, z);
	free(arr);
	free(pow);
	g_ipart = num_len(g_ipart);
	copy_long_double(z, n, sign);
	free(z);
}

void					long_double_work(t_pf *data, va_list args)
{
	long double			fl;
	__int128			*ptr;
	short				sign;
	short				exp;
	unsigned long long	mant;

	fl = (long double)va_arg(args, long double);
	ptr = (__int128 *)&fl;
	sign = (*ptr) >> 79;
	if (sign == 1)
		fl *= (-1);
	g_ipart = (__int128)fl;
	g_fpart = fl - g_ipart;
	exp = ((*ptr) >> 64) - 16383;
	mant = (unsigned long long)*ptr;
	if (data->precision == 0)
		data->precision = 6;
	if (g_fpart != 0 && fl != 1.0 / 0.0 && fl != -1.0 / 0.0 && fl == fl)
		get_dfloat(mant, exp, sign);
	else if (fl != 1.0 / 0.0 && fl != -1.0 / 0.0 && fl == fl)
		ipart_to_str();
	if (g_buffer->str[0] == '-')
		DEL_BIT(data->flags, 3);
}
