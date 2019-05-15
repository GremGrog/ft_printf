#include "../../MainHeader/ft_printf.h"

void				ft_copy_float(char *x, short sign)
{
	int				i;
	int				j;

	j = 0;
	g_ipart = num_len(g_ipart);
	i = 0;
	while (x[i] + '0' != '.')
		i++;
	check_and_add(g_buffer->str_len + i);
	if (sign == 1)
	{
		g_buffer->str[j] = '-';
		j = 1;
		g_ipart--;
	}
	i += g_ipart;
	while (i >= 0)
		g_buffer->str[j++] = x[i--] + '0';
	g_buffer->str[j] = '\0';
	g_buffer->str_len = j;
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
	pow = (char *)malloc(sizeof(char) * 200);
	bow = (char *)malloc(sizeof(char) * 200);
	z = (char *)malloc(sizeof(char) * 200);
	x = malloc(sizeof(char) * 200);
	set_arr_to_null(bow);
	set_arr_to_null(pow);
	set_arr_to_null(z);
	set_arr_to_null(x);
	pow = get_five_power(exp, pow, bow);
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
	arr = malloc(sizeof(char) * 200);
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
	arr[i] = '\0';
	if ((52 - exp) > 0)
		get_float(arr, exp, sign);
	else
		other_case(arr, exp, sign);
}

void				get_mes(double flo)
{
	unsigned long	*ptr;
	short			sign;
	short			exp;
	long long		mant;

	ptr = (unsigned long*)&flo;
	sign = (*ptr) >> 63;
	exp = ((*ptr) >> 52) - 1023;
	exp <<= 5;
	exp >>= 5;
	mant = (*ptr) << 12 >> 12;
	get_mant_plus_pow(mant, exp, sign);
}

t_pf				*ft_floats(t_pf *data, va_list args)
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
	return (data);
}
