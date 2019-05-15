#include "../../MainHeader/ft_printf.h"

void		grid_o(t_pf *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (g_buffer->str[0] == '0')
		return ;
	g_buffer->final[i++] = '0';
	while (g_buffer->str[j] != '\0')
		g_buffer->final[i++] = g_buffer->str[j++];
	g_buffer->final[i] = '\0';
	g_buffer->str_len = i;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size);
}
