#include "../../MainHeader/ft_printf.h"

void	ft_put_precision_pointer(t_pf *data)
{
	int		i;
	int		j;
	int		len;

	if (!data->precision)
		return ;
	if (data->precision == -1 && g_buffer->str[0] == '0')
	{
		g_buffer->str[0] = '\0';
		g_buffer->str_len = 0;
		return ;
	}
	data->indents_symb = ' ';
	len = g_buffer->str_len - data->precision;
	if (len >= 0)
		return ;
	check_and_add(len * (-1));
	i = -1;
	while (++i < (-len))
		g_buffer->final[i] = '0';
	j = -1;
	while (g_buffer->str[++j] != '\0' && g_buffer->str[j])
		g_buffer->final[i++] = g_buffer->str[j];
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, i);
}
