#include "push_swap.h"

void	shorten(t_stack **instr)
{
	replace_swaps(instr);
	replace_rotates(instr);
	replace_pushes(instr);
	replace_pushswap(instr);
	replace_r_rr(instr);
}

void	free_inf(t_inf **inf)
{
	stack_free(&(*inf)->a);
	stack_free(&(*inf)->b);
	stack_free(&(*inf)->instr);
	free(*inf);
}

int		main(int argc, char **argv)
{
	int		*int_list;
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
	sort_stack(&inf, &chunks_a, &chunks_b);
	shorten(&(inf->instr));
	print_instr(inf->instr);
	free_inf(&inf);
	free_main(&chunks_a, &chunks_b);
}