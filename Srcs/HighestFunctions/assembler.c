#include "../../MainHeader/ft_printf.h"

void		ft_print_zero(t_pf *data)
{
	char	sym;

	sym = 0;
	data->return_value = g_buffer->str_len + g_buffer->before_len +
			g_buffer->after_len + 1;
	if (data->str_before)
	{
		write(1, data->str_before, g_buffer->before_len);
		free(data->str_before);
	}
	if (g_buffer->str)
		write(1, g_buffer->str, g_buffer->str_len);
	write(1, &sym, 1);
	if (data->str_after)
	{
		write(1, data->str_after, g_buffer->after_len);
		free(data->str_after);
	}
}

t_pf		*assemble_string(t_pf *data)
{
	if (data->type == '0')
	{
		ft_print_zero(data);
		return (data);
	}
	ft_put_str(data);
	data->return_value = g_buffer->str_len + g_buffer->before_len +
						g_buffer->after_len;
	return (data);
}
