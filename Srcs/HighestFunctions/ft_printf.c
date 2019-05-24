/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:01:11 by qmebble           #+#    #+#             */
/*   Updated: 2019/05/24 21:42:57 by fmasha-h         ###   ########.fr       */
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
	ft_printf("o%.32f\n", 2.33456);
	printf("s%.32f", 2.33456);
//	printf("%c|%-c|%12c|%-12c", 0, 0, 0, 0);
//	printf("%.2147483649f|%2147483649f", 1.0, 1.0);
//	printf("%.f\n", 45.5);
//	ft_printf("%.f\n", 44.5);
//	printf("%.f\n", 44.5);
//	float		nb;
//	nb = 12.5;
//	ft_printf("null prec : %+.0f\n", nb);
//	dprintf(2, "null prec : %+.0f\n", nb);

}