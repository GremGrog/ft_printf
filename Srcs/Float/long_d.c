#include "../../MainHeader/ft_printf.h"

void					long_double_work(t_pf *data, va_list args)
{
	long double			fl;

	fl = (long double)va_arg(args, long double);
	g_ipart = (long)fl;
	g_fpart = fl - g_ipart;
	if (data->precision == 0)
		data->precision = 6;
	if (g_fpart != 0 && fl != 1.0 / 0.0 && fl != -1.0 / 0.0 && fl == fl)
		get_mes(fl);
	else if (fl != 1.0 / 0.0 && fl != -1.0 / 0.0 && fl == fl)
		ipart_to_str();
	if (g_buffer->str[0] == '-')
		DEL_BIT(data->flags, 3);
}
