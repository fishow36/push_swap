#include "push_swap.h"

void	shorten(t_stack **instr)
{
	replace_swaps(instr);
	replace_rotates(instr);
	replace_pushes(instr);
	replace_pushswap(instr);
	replace_r_rr(instr);
}

int		main(int argc, char **argv)
{
	int		*int_list;
	t_stack *a;
	t_stack *chunks_a;
	t_stack *chunks_b;
	t_inf	*inf;

	if (argc == 1)
		return (0);
	if ((int_list = list_validation(argc, argv, 0)) == NULL)
	{
		ft_printf("%s\n", "Error");
		return(0);
	}
	inf = (t_inf*)malloc(sizeof(t_inf));
	inf->a = create_stack_a(argc - 1, int_list);
	free(int_list);
	inf->instr = NULL;
	inf->b = NULL;
	chunks_a = stack_new(argc - 1);
	chunks_b = NULL;
	sort_stack(&(inf->a), &(inf->b), &(inf->instr), &chunks_a, &chunks_b);
	// print_stack(a);
	// print_stack(b);
	shorten(&(inf->instr));
	print_instr(inf->instr);
	// ft_printf("total: %d instructions\n", stack_len(instr));
	// free_main(&a, &b, &instr);
	// free_main(&chunks_a, &chunks_b, &instr);
}