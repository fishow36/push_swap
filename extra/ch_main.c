#include "push_swap.h"

int main(int argc, char **argv)
{
	int		i;
	int		*int_list;

	if (argc == 1)
		return (0);
	if ((int_list = list_validation(argc, argv)) == NULL)
	{
		ft_printf("%s\n", "Error");
		return(0);
	}
	check_instr(int_list, argc - 1);
	return (0);
}