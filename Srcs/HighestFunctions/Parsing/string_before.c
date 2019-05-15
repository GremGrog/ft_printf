#include "../../../MainHeader/ft_printf.h"

int			string_before(t_pf *data, const char *format, int i)
{
	int	l;
	int	j;

	j = 0;
	l = 0;
	while (format[i] != '%' && format[i])
	{
		i++;
		l++;
	}
	i -= l;
	data->str_before = (char*)malloc(sizeof(char) * l + 1);
	while (j < l)
	{
		data->str_before[j] = format[i];
		j++;
		i++;
	}
	data->str_before[l] = '\0';
	g_buffer->before_len = i;
	return (i);
}
