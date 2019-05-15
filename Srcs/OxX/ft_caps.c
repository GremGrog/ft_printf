#include "../../MainHeader/ft_printf.h"

void		ft_caps(t_pf *list)
{
	int		i;

	if (list->type != 'X')
		return ;
	i = 0;
	while (g_buffer->str[i] && g_buffer->str[i] != '\0')
	{
		if (g_buffer->str[i] >= 'a' && g_buffer->str[i] <= 'z')
			g_buffer->str[i] -= 32;
		i++;
	}
}
