/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:49 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/18 19:12:28 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void				ft_copy_float(char *x, short sign)
{
	int				i;
	int				j;
	int				o;
	int				l;
	int				dot;

	dot = 0;
	j = 0;
	i = 0;
	o = 398;
	while (x[i] == 0)
		i++;
	while (x[o] == 0)
		o--;
	if (i == 1)
		i--;
	l = o - i;
	check_and_add(g_buffer->str_len + l);
	if (sign == 1)
		g_buffer->str[j++] = '-';
	while (l >= 0)
		g_buffer->str[j++] = x[l--] + '0';
	g_buffer->str_len = j;
	get_ipart();
	free(x);
}

void				get_float(char *y, short exp, short sign)
{
	char			*z;
	char			*pow;
	char			*bow;
	int				n;
	char			*x;

	n = 52 - exp;
	pow = (char *)malloc(sizeof(char) * 399);
	bow = (char *)malloc(sizeof(char) * 399);
	z = (char *)malloc(sizeof(char) * 399);
	x = malloc(sizeof(char) * 399);
	if (!pow || !bow || !z || !x)
		return ;
	set_arr_to_null(bow);
	set_arr_to_null(pow);
	set_arr_to_null(z);
	set_arr_to_null(x);
	pow = get_five_power(52, exp, pow, bow);
	multiplication_long(pow, y, z);
	div_l(z, n, x);
	free(z);
	free(pow);
	free(y);
	ft_copy_float(x, sign);
}

void				get_mant_plus_pow(unsigned long mant, short exp, short sign)
{
	char			*arr;
	int				i;
	long			a_pow;

	i = 0;
	a_pow = 4503599627370496;
	if (!(arr = malloc(sizeof(char) * 399)))
		return ;
	set_arr_to_null(arr);
	number_to_arr(mant, arr);
	while (a_pow > 0)
	{
		arr[i] = ((arr[i] + (a_pow % 10)));
		if (arr[i] >= 10)
		{
			arr[i] %= 10;
			arr[i + 1] += 1;
		}
		i++;
		a_pow /= 10;
	}
	if ((52 - exp) > 0)
		get_float(arr, exp, sign);
	else
		other_case(arr, exp, sign);
}

void				get_mes(double flo)
{
	unsigned long long	*ptr;
	short				sign;
	short				exp;
	unsigned long long	mant;

	ptr = (unsigned long long *)&flo;
	sign = (*ptr) >> 63;
	exp = ((*ptr) >> 52) - 1023;
	exp <<= 5;
	exp >>= 5;
	mant = (*ptr) << 12 >> 12;
	get_mant_plus_pow(mant, exp, sign);
}

void				ft_floats(t_pf *data, va_list args)
{
	double			flo;

	if (!CHECK_BIT(data->modificators, 0))
	{
		flo = (double)va_arg(args, double);
		g_ipart = (long)flo;
		g_fpart = flo - g_ipart;
		if (data->precision == 0)
			data->precision = 6;
		if (g_fpart != 0 && flo != 1.0 / 0.0 && flo != -1.0 / 0.0 && flo == flo)
			get_mes(flo);
		else if (flo != 1.0 / 0.0 && flo != -1.0 / 0.0 && flo == flo)
			ipart_to_str();
		else
			validity(flo);
		if (g_buffer->str[0] == '-')
			DEL_BIT(data->flags, 3);
	}
	else
		long_double_work(data, args);
	set_plus_flo(data);
	set_precision_flo(data);
	set_space_flo(data);
	set_indents_flo(data);
	ft_put_color(data);
}
