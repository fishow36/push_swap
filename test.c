#include "push_swap.h"

int main()
{
	char *str;

	get_next_line(1, &str);
	ft_printf("%s\n", str);
	if (str)
		ft_strdel(&str);
}