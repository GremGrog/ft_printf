#include "../../MainHeader/ft_printf.h"

void				multiplication_on_short(char *src, int num, char *dst)
{
	int				i;
	int				temp;
	int				d;

	i = 0;
	while (i < 200)
	{
		temp = src[i] * num;
		if (temp >= 10)
		{
			dst[i] += temp % 10;
			if (dst[i] >= 10)
			{
				d = dst[i];
				dst[i] = d % 10;
				dst[i + 1] += d / 10;
			}
			else
				dst[i + 1] = temp / 10;
		}
		else
			dst[i] += temp;
		i++;
	}
}

char				*get_five_power(short exp, char *pow, char *bow)
{
	int				n;

	n = 52;
	n -= exp;
	pow[0] = 5;
	if (!(n > 1))
		return (pow);
	while (n > 0)
	{
		multiplication_on_short(pow, 5, bow);
		set_arr_to_null(pow);
		n--;
		if (n == 1)
		{
			free(pow);
			return (bow);
		}
		multiplication_on_short(bow, 5, pow);
		set_arr_to_null(bow);
		n--;
		if (n == 1)
			break ;
	}
	free(bow);
	return (pow);
}

void				multiplication_loop(int j, char *x, char *y, char *z)
{
	int				temp;
	int				i;

	i = 0;
	while (i < 200 && (i + j) < 200)
	{
		temp = z[i + j] + (x[i] * y[j]);
		if (temp >= 10)
		{
			z[i + j] = temp % 10;
			if (z[i + j] >= 10)
			{
				z[i + j] = z[i + j] % 10;
				z[i + j + 1] += z[i + j] / 10;
			}
			else
				z[i + j + 1] += temp / 10;
		}
		else
			z[i + j] = temp;
		i++;
	}
}

void				multiplication_long(char *x, char *y, char *z)
{
	int				j;

	j = 0;
	while (j < 200)
	{
		multiplication_loop(j, x, y, z);
		j++;
	}
}

void				div_l(char *z, int n, char *y)
{
	int				temp;
	int				i;
	int				j;

	i = 0;
	j = 0;
	temp = n;
	while (z[i] == 0)
	{
		n--;
		i++;
	}
	while (n-- > 0)
	{
		y[j++] = z[i++] % 10;
		if (n == 0)
			y[j++] = -2;
	}
	i = 199;
	while (z[i] == 0)
		i--;
	temp = i - temp + 1;
	while (--temp >= 0)
		y[j++] = z[i - temp] % 10;
}
