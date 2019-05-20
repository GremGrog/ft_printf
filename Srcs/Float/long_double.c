/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:21 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/20 16:06:46 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

int					get_ldoble_next(char *z, short s)
{
	char		*pow;
	char		*bow;
	char		*arr;

	if (!(arr = (char *)malloc(sizeof(char) * 4999)))
		return (-1);
	if (!(pow = (char *)malloc(sizeof(char) * 4999)))
	{
		free(arr);
		return (-1);
	}
	if (!(bow = (char *)malloc(sizeof(char) * 4999)))
	{
		free_arrays(&arr, &pow);
		return (-1);
	}
	set_arrays_to_null(pow, bow, 4999);
	set_arr_to_null(arr, 4999);
	pow = get_five_power_ld(63, 0, pow, bow);
	multiplication_long_ld(z, pow, arr);
	set_arr_to_null(z, 4999);
	long_arithmetic_div_ld(arr, 63, z);
	free_arrays(&pow, &arr);
	copy_long_double_other(z, s);
	return (0);
}

void				get_longdouble_other(unsigned long long m, short e, short s)
{
	char		*arr;
	char		*pow;
	char		*bow;
	char		*z;

	pow = (char *)malloc(sizeof(char) * 4999);
	bow = (char *)malloc(sizeof(char) * 4999);
	arr = (char *)malloc(sizeof(char) * 4999);
	if (!pow || !bow || !arr)
		return (check_and_free(&pow, &bow, &arr, NULL));
	if (!(z = (char *)malloc(sizeof(char) * 4999)))
	{
		free_arrays(&pow, &bow);
		free(arr);
		return ;
	}
	set_arrays_to_null(pow, bow, 4999);
	set_arrays_to_null(arr, z, 4999);
	pow = get_two_power_ld(e, pow, bow);
	number_to_arr(m, arr);
	multiplication_long_ld(arr, pow, z);
	free_arrays(&pow, &arr);
	if (get_ldoble_next(z, s) == -1)
		free(z);
}

void				get_longdouble(unsigned long long m, short exp, short sign)
{
	char		*arr;
	char		*pow;
	char		*bow;
	char		*z;

	if (63 - exp > 0)
	{
		arr = (char *)malloc(sizeof(char) * 399);
		pow = (char *)malloc(sizeof(char) * 399);
		bow = (char *)malloc(sizeof(char) * 399);
		z = (char *)malloc(sizeof(char) * 399);
		if (!arr || !pow || !bow || !z)
			return (check_and_free(&arr, &pow, &bow, &z));
		set_arrays_to_null(pow, bow, 399);
		set_arrays_to_null(z, arr, 399);
		pow = get_five_power(63, exp, pow, bow);
		number_to_arr(m, arr);
		multiplication_long(arr, pow, z);
		free_arrays(&arr, &pow);
		copy_long_double(z, 63 - exp, sign);
		free(z);
	}
	else
		get_longdouble_other(m, exp, sign);
}

void				long_double_work(t_pf *data, va_list args)
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
	exp = ((*ptr) >> 64) - 16383;
	mant = (unsigned long long)*ptr;
	if (data->precision == 0)
		data->precision = 6;
	if (fl != 0 && fl != 1.0 / 0.0 && fl != -1.0 / 0.0 && fl == fl)
		get_longdouble(mant, exp, sign);
	else if (fl != 1.0 / 0.0 && fl != -1.0 / 0.0 && fl == fl)
		ipart_to_str();
	if (g_buffer->str[0] == '-')
		DEL_BIT(data->flags, 3);
}