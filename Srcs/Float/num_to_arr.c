#include "../../MainHeader/ft_printf.h"

void		number_to_arr(unsigned long mant, char *arr)
{
	int		i;

	i = 0;
	while (mant > 0)
	{
		arr[i++] = mant % 10;
		mant /= 10;
	}
}
