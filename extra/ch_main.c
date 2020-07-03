#include "push_swap.h"

int main(int argc, char **argv)
{
	int		i;
	int		*int_list;
	int		v;

	if (argc == 1)
		return (0);
	v = 0;
	if (ft_strcmp(argv[1], "-v") == 0)
		v = 1;
	if ((int_list = list_validation(argc, argv, v)) == NULL)
	{
		ft_printf("%s\n", "Error");
		return(0);
	}
	check_instr(int_list, argc - (v + 1), v);
	return (0);
}