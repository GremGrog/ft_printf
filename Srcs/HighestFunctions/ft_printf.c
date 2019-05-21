/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:11 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/21 20:10:15 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int main()
{
//	printf("S%.5lld|%-.5lld|%+.5lld|% .5lld|%0.5lld\n", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
//	ft_printf("O%.5lld|%-.5lld|%+.5lld|% .5lld|%0.5lld\n", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
//	printf("S%1.5lld|%-1.5lld|%+1.5lld|% 1.5lld|%01.5lld\n", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
//	ft_printf("O%1.5lld|%-1.5lld|%+1.5lld|% 1.5ld|%01.5lld\n", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN);
//
//	printf("%.5f|%.12f\n", 61.000099, 61.000099);
	ft_printf("%.12f", 61.000099);
//	printf("%5f|%-5f|%+5f|% 5f|%#5f|%05f\n", 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0);
//	ft_printf("%5f|%-5f|%+5f|% 5f|%#5f|%05f\n", 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0);
//	printf("%.f|%-.f|%+.f|% .f|%#.f|%0.f\n", 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0);
//	ft_printf("%.f|%-.f|%+.f|% .f|%#.f|%0.f\n", 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0);
//	printf("%.8f|%-.8f|%+.8f|% .8f|%#.8f|%0.8f\n", 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0);
//	ft_printf("%.8f|%-.8f|%+.8f|% .8f|%#.8f|%0.8f\n", 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0, 1.0/0.0);

}