#include "../../MainHeader/ft_printf.h"

void	set_plus_flo(t_pf *data)
{
	int		i;
	int		j;

	if (!CHECK_BIT(data->flags, 4) || g_buffer->str[0] == '-')
		return ;
	i = 0;
	j = 0;
	g_buffer->final[j] = '+';
	j++;
	while (g_buffer->str[i] != '\0')
		g_buffer->final[j++] = g_buffer->str[i++];
	g_buffer->str_len = j;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}
