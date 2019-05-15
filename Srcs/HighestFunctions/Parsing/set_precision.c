#include "../../../MainHeader/ft_printf.h"

int	set_precision(t_pf *data, const char *format, int i)
{
	i += 1;
	if (char_bin_search(NUMBERS, format[i]) == -1)
	{
		data->precision = -1;
		return (i);
	}
	while (char_bin_search(NUMBERS, format[i]) != -1)
	{
		data->precision = data->precision * 10 + format[i] - '0';
		i++;
	}
	if (data->precision == 0)
		data->precision = -1;
	return (i);
}
