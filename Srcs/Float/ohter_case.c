/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ohter_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:36:02 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/05/17 17:36:02 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MainHeader/ft_printf.h"

void				set_arr_to_null(char *arr)
{
	int				i;

	i = 0;
	while (i < 200)
	{
		arr[i] = 0;
		i++;
	}
}

int					ft_binpow(long a, long n)
{
	long			res;

	res = 1;
	while (n)
	{
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return (res);
}

void				ft_copy_float_other(char *x, short sign)
{
	int				i;
	int				j;

	j = 0;
	i = -1;
	g_ipart = num_len(g_ipart);
	if (sign == 1)
	{
		g_buffer->str[j] = '-';
		j = 1;
		g_ipart--;
	}
	i += g_ipart;
	check_and_add(g_buffer->str_len + i);
	while (i >= 0)
		g_buffer->str[j++] = x[i--] + '0';
	g_buffer->str[j] = '.';
	g_buffer->str_len = j;
	free(x);
}

void				other_case(char *y, short exp, short sign)
{
	int				n;
	long			res;
	char			*x;
	char			*z;

	n = 52;
	n = exp - n;
	res = ft_binpow(2, n);
	if (!(x = (char*)malloc(sizeof(char) * 200)))
		return ;
	if (!(z = (char*)malloc(sizeof(char) * 200)))
	{
		free(x);
		free(z);
		free(y);
		return ;
	}
	set_arr_to_null(x);
	set_arr_to_null(z);
	number_to_arr(res, z);
	multiplication_long(y, z, x);
	free(z);
	free(y);
	ft_copy_float_other(x, sign);
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
