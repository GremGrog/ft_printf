#include "../../MainHeader/ft_printf.h"

int				char_bin_search(char *str, char symb)
{
	short int	left;
	short int	right;
	short int	middle;
	short int	search;

	left = 0;
	search = -1;
	right = ft_strlen(str);
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (str[middle] == symb)
		{
			search = middle;
			return (middle);
		}
		if (symb < str[middle])
			right = middle - 1;
		else
			left = middle + 1;
	}
	if (search == -1)
		return (-1);
	return (middle);
}
