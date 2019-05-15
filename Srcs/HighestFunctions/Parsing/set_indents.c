#include "../../../MainHeader/ft_printf.h"

int	set_indents(t_pf *data, const char *format, int i)
{
	while (char_bin_search(NUMBERS, format[i]) != -1)
	{
		data->indents = data->indents * 10 + format[i] - '0';
		i++;
	}
	return (i);
}
