#include "../../MainHeader/ft_printf.h"

void		ft_fill_zero(t_pf *data)
{
	int		i;

	i = 0;
	while (data->precision >= 0)
	{
		g_buffer->final[i++] = '0';
		data->precision--;
	}
	g_buffer->str_len = i;
//	ft_bzero(g_buffer->str, g_buffer->buff_size + 1);
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void		fill_precision_grid(t_pf *data)
{
	int		i;
	int		j;

	if (data->type != 'o')
	{
		if (g_buffer->str[1] != 'X' && g_buffer->str[1] != 'x')
		{
			ft_fill_zero(data);
			return ;
		}
		g_buffer->final[0] = '0';
		g_buffer->final[1] = 'x';
		i = 2;
		j = 2;
	}
	else
	{
		g_buffer->final[0] = '0';
		i = 1;
		j = 1;
	}
	while (data->precision-- > 0)
		g_buffer->final[i++] = '0';
	while (g_buffer->str[j] != '\0')
		g_buffer->final[i++] = g_buffer->str[j++];
	g_buffer->final[i] = '\0';
	g_buffer->str_len = i;
	ft_bzero(g_buffer->str, g_buffer->buff_size + 1);
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void		fill_str_ox(t_pf *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->precision > 0)
	{
		g_buffer->final[i++] = '0';
		data->precision--;
	}
	while (g_buffer->str[j] != '\0')
		g_buffer->final[i++] = g_buffer->str[j++];
	g_buffer->final[i] = '\0';
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}

void		fill_precision_ox(t_pf *data)
{
	int		len;

	if (!(data->precision > 0))
	{
		if (data->type == 'o' && CHECK_BIT(data->flags, 2) && g_buffer->str[0] == '0')
			return ;
		if ((data->type != 'o' && g_buffer->str[0] == '0' && g_buffer->str[1] != 'x')
		|| (data->type == 'o' && data->precision == -1 && g_buffer->str[0] == '0')
		|| g_buffer->str[0] == '\0')
		{
			g_buffer->str[0] = '\0';
			g_buffer->str_len = 0;
			return ;
		}
	}
	len = g_buffer->str_len - data->precision;
	if (len >= data->precision)
		return ;
	len *= -1;
	check_and_add(len);
	if (data->type != 'o' && CHECK_BIT(data->flags, 2))
		len += 2;
	data->precision = len;
	if (CHECK_BIT(data->flags, 2))
		fill_precision_grid(data);
	fill_str_ox(data);
}
