#include "../../MainHeader/ft_printf.h"

void	ft_strrev(void)
{
	int		i;
	int		j;
	int		len;

	len = g_buffer->str_len;
	i = 0;
	j = len - 1;
	while (i < len)
		g_buffer->final[i++] = g_buffer->str[j--];
	while (i < g_buffer->buff_size)
		g_buffer->final[i++] = '\0';
	ft_strcpy(g_buffer->str, g_buffer->final);
	ft_bzero(g_buffer->final, g_buffer->buff_size);
}
