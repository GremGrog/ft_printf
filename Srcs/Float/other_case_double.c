/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ohter_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:36:02 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/20 16:16:16 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void				set_arr_to_null(char *arr, int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

void				other_case_double(char *y, short exp, short sign)
{
	int				n;
	char			*x;
	char			*z;
	char			*pow;
	char			*bow;

	n = exp - 52;
	x = (char*)malloc(sizeof(char) * 399);
	z = (char*)malloc(sizeof(char) * 399);
	pow = (char *)malloc(sizeof(char) * 399);
	bow = (char *)malloc(sizeof(char) * 399);
	if (!x || !z || !pow || !bow)
		return (check_and_free(&x, &z, &pow, &bow));
	set_arrays_to_null(x, y, 399);
	set_arrays_to_null(pow, bow, 399);
	pow = get_two_power(n, pow, bow);
	multiplication_long(y, pow, x);
	free_arrays(&z, &y);
	free(pow);
	ft_copy_float(x, sign);
}

void				validity(double flo)
{
	if (flo == 1.0 / 0.0)
	{
		ft_strcpy(g_buffer->str, "inf");
		g_buffer->str_len = 3;
	}
	else if (flo == -1.0 / 0.0)
	{
		ft_strcpy(g_buffer->str, "-inf");
		g_buffer->str_len = 4;
	}
	else if (flo != flo)
	{
		ft_strcpy(g_buffer->str, "nan");
		g_buffer->str_len = 3;
	}
}
