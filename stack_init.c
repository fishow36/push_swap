#include "push_swap.h"

void	sort(t_stack *a, t_stack *b, t_stack *instr)
{
	t_stack *temp_a;
	t_stack *temp_b;

	
}

t_stack *find_instr(int *list, int len)
{
	t_stack *a;
	t_stack *b;
	t_stack	*instr;

	a = create_stack_a(len, list);
	b = NULL;
	instr = NULL;

	stack_free(&a);
	stack_free(&b);
	return(instr);
}
