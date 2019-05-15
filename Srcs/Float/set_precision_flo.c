#include "../../MainHeader/ft_printf.h"

void		round_up(t_pf *data, int i, int j)
{
	while (data->precision > 0)
	{
		g_buffer->final[j++] = g_buffer->str[i++];
		if (g_buffer->str[i + 1] == '9')
		{
			if (g_buffer->str[i] == '9')
				g_buffer->str[i] = '0';
			else
				g_buffer->str[i]++;
		}
		if (data->precision == 0 && g_buffer->str[i + 1] >= '5')
			g_buffer->final[j] = g_buffer->str[i]++;
		if (g_buffer->str[i] == '\0')
		{
			while (data->precision > 0)
			{
				g_buffer->final[j++] = '0';
				data->precision--;
			}
		}
		data->precision--;
	}
	g_buffer->str_len = j;
}

void		copy_flo(t_pf *data, int i, int j)
{
	while (data->precision > 0 && g_buffer->str[i] != '\0')
	{
		if (data->precision == 1 && g_buffer->str[i + 1] >= '5')
			g_buffer->final[j] = g_buffer->str[i]++;
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
	while (g_buffer->str[i - 1] != '.')
	{
		g_buffer->final[j++] = g_buffer->str[i++];
		if (data->precision <= 0)
		{
			if (g_buffer->str[i] == '.' && (g_ipart > 1) &&
				(g_fpart >= 0.51 || g_fpart <= (-0.51)))
				g_buffer->final[j - 1]++;
			if (!CHECK_BIT(data->flags, 2))
			{
				if (g_buffer->str[i] == '.')
					break ;
			}
		}
	}
	if (g_buffer->str[i + data->precision] == '9')
		round_up(data, i, j);
	else
		copy_flo(data, i, j);
}

void		set_precision_flo(t_pf *data)
{
	int		i;
	int		j;

	if (g_fpart == 1.0 / 0.0 || g_fpart == -1.0 / 0.0 || g_fpart != g_fpart)
		return ;
	i = 0;
	j = 0;
	round_up_ipart(i, j, data);
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}
