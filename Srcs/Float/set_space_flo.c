#include "../../MainHeader/ft_printf.h"

void		set_space_flo(t_pf *data)
{
	int		i;
	int		j;

	if (!CHECK_BIT(data->flags, 3))
		return ;
	i = 0;
	j = 0;
	g_buffer->final[j++] = ' ';
	while (g_buffer->str[i] != '\0')
	{
		g_buffer->final[j] = g_buffer->str[i];
		i++;
		j++;
	}
	g_buffer->str_len = j;
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
}
