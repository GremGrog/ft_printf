#include "../../MainHeader/ft_printf.h"

void		ft_pointer(t_pf *data, va_list args)
{
	g_pointer = va_arg(args, unsigned long long int);
	ft_itoa_pointer(g_pointer);
	ft_put_precision_pointer(data);
	ft_put_grid_pointer(data);
	ft_put_indents_pointer(data);
}
