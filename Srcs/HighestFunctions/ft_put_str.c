#include "../../MainHeader/ft_printf.h"

void	ft_put_str(t_pf *data)
{
	char	*final;
	int		x;
	int		y;
	int		z;

	final = (char *)malloc(sizeof(char) * (g_buffer->before_len +
			g_buffer->str_len + g_buffer->after_len + 1));
	x = 0;
	if (data->str_before)
	{
		while (x < g_buffer->before_len)
		{
			final[x] = data->str_before[x];
			x++;
		}
		free(data->str_before);
	}
	y = 0;
	if (g_buffer->str)
	{
		while (y < g_buffer->str_len)
		{
			final[x + y] = g_buffer->str[y];
			y++;
		}
//		free(data->str_middle);
	}
	z = 0;
	if (data->str_after)
	{
		while (z < g_buffer->after_len)
		{
			final[x + y + z] = data->str_after[z];
			z++;
		}
		free(data->str_after);
	}
	final[x + y + z] = '\0';
	write(1, final, x + y + z);
	free(final);
}
