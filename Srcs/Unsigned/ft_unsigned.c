#include "../../MainHeader/ft_printf.h"

void	ft_unsigned(t_pf *data, va_list args)
{
	g_unsigned_integer = check_limits_unsigned(data, args);
	if (CHECK_BIT(data->flags, 6))
		ft_itoa_u_binary(data, g_unsigned_integer);
	else
		ft_itoa_unsigned(g_unsigned_integer);
	ft_put_precision_unsigned(data);
	ft_put_indents_unsigned(data);
}
