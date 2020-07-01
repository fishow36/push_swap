#include "push_swap.h"

void	shorten(t_stack **instr)
{
	replace_swaps(instr);
	replace_rotates(instr);
	replace_pushes(instr);
	replace_pushswap(instr);
	replace_r_rr(instr);
}

int	main(int argc, char **argv)
{
	int		i;
	int		*int_list;
	t_stack	*instr;
	t_stack *a;
	t_stack *b;
	t_stack *chunks_a;
	t_stack *chunks_b;

	if (argc == 1)
		return (0);
	if ((int_list = list_validation(argc, argv, 0)) == NULL)
	{
		ft_printf("%s\n", "Error");
		return(0);
	}
	a = create_stack_a(argc - 1, int_list);
	free(int_list);
	instr = NULL;
	b = NULL;
	chunks_a = stack_new(argc - 1);
	chunks_b = NULL;
	sort_stack(&a, &b, &instr, &chunks_a, &chunks_b);
	print_stack(a);
	print_stack(b);
	shorten(&instr);
	print_instr(instr);
	ft_printf("total: %d instructions\n", stack_len(instr));
	stack_free(&a);
	stack_free(&b);
	stack_free(&chunks_a);
	stack_free(&chunks_b);
	stack_free(&instr);

}