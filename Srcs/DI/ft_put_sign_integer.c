#include "../../MainHeader/ft_printf.h"

void	ft_put_sign_integer(t_pf *data)
{
	int		i;

	if (g_buffer->str[0] == '-' || !CHECK_BIT(data->flags, 4))
		return ;
	i = 0;
	check_and_add(g_buffer->str_len + 1);
	g_buffer->final[i] = '+';
	while (g_buffer->str[i] != '\0')
	{
		g_buffer->final[i + 1] = g_buffer->str[i];
		i++;
	}
	g_buffer->str_len = i + 1;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}
