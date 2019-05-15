#include "../../MainHeader/ft_printf.h"

void	ft_put_grid_pointer(t_pf *data)
{
	int		i;

	check_and_add(g_buffer->str_len + 2);
	g_buffer->final[0] = '0';
	g_buffer->final[1] = 'x';
	i = 2;
	while (g_buffer->str[i - 2] && g_buffer->str[i - 2] != '\0')
	{
		g_buffer->final[i] = g_buffer->str[i - 2];
		i++;
	}
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, i);
}
