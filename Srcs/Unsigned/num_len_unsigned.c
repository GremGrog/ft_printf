#include "../../MainHeader/ft_printf.h"

int	num_len_unsigned(unsigned long long int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}
