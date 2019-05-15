#include "../../MainHeader/ft_printf.h"

void	ft_di(t_pf *data, va_list args)
{
	g_integer = check_limits_integer(data, args);
	if (CHECK_BIT(data->flags, 6))
		ft_itoa_int_binary(data, g_integer);
	else
		ft_itoa_integer(g_integer);
	ft_put_precision_integer(data);
	ft_put_sign_integer(data);
	ft_put_space_integer(data);
	ft_put_indents_integer(data);
}
