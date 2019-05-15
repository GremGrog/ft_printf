#include "../../../MainHeader/ft_printf.h"

void	check_for_flags(t_pf *data)
{
	if (CHECK_BIT(data->flags, 1))
	{
		if (!(CHECK_BIT(data->flags, 5)))
			data->indents_symb = '0';
		else
		{
			data->indents_symb = ' ';
			DEL_BIT(data->flags, 1);
		}
	}
	else
		data->indents_symb = ' ';
	if (CHECK_BIT(data->flags, 3))
		if (CHECK_BIT(data->flags, 4))
			DEL_BIT(data->flags, 3);
}

int		wheel(t_pf *data, const char *format, int i)
{
	while (format[i] != '\0')
	{
		if (char_bin_search(FLAGS, format[i]) != -1 && format[i])
			i = set_flags(data, format, i);
		else if (char_bin_search(NUMBERS, format[i]) != -1 && format[i] != '\0')
			i = set_indents(data, format, i);
		else if (format[i] == '.')
			i = set_precision(data, format, i);
		else if (format[i] == 'h' || format[i] == 'l' ||
			format[i] == 'L' || format[i] == 'z')
			i = set_modificators(data, format, i);
		else if (char_bin_search(TYPES, format[i]) != -1 && format[i] != '\0')
		{
			data->type = format[i++];
			break ;
		}
		else if (char_bin_search(TYPES, format[i]) == -1 && format[i] != '\0')
			break ;
		else
			i++;
	}
	return (i);
}

int		ft_parsing(t_pf *data, va_list args, const char *format, int i)
{
	ft_set_to_null(data);
	make_new_buffer();
	if (format[i] != '%')
		i = string_before(data, format, i);
	if (format[i] == '%')
		i += 1;
	i = wheel(data, format, i);
	if (format[i] != '%' && format[i])
		i = ft_str_after(data, format, i);
	check_for_flags(data);
	assemble_string(put_data(data, args));
	return (i);
}
