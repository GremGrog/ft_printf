#include "../../MainHeader/ft_printf.h"
#include <limits.h>
int			ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	t_pf	*data;
	int		return_value;

	if (!format)
		return (-1);
	i = 0;
	return_value = 0;
	data = (t_pf *)malloc(sizeof(t_pf));
	va_start(args, format);
	while (format[i] && format[i] != '\0')
	{
		i = ft_parsing(data, args, format, i);
		return_value += data->return_value;
		free_buffer();
	}
	ft_set_to_null(data);
	free(data);
	va_end(args);
	return (return_value);
}
//
//////
//int main()
//{
//	double		nb;
//	nb = -12547.58;
//
//
//	ft_printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb);
//	printf("______________________________________________________________________________\n");
//
//	dprintf(2, "size + minus + plus + prec + hash:%-#+5.0f\n", nb);
//}
////

