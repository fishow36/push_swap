#include "push_swap.h"

/* -1 -- error */
/* 1 -- finished */
int	sort_stack(t_stack **a, t_stack **b, t_stack **instr, t_stack **chunks_a, t_stack **chunks_b)
{
	int	*list;
	int len;
	int sent;

	if (*a && *chunks_a && is_sorted(*a, (*chunks_a)->num, 'a') == 0)
	{
		len = (*chunks_a)->num;
		if (len == 1 && stack_len(*chunks_a) > 1)
		{
			stack_pop(chunks_a);
			(*chunks_a)->num++;
		}
		else if (len == 2)
		{
			sort_2(a, 'a', instr);
			if (stack_len(*chunks_a) > 1)
			{
				stack_pop(chunks_a);
				(*chunks_a)->num += 2;
			}
		}
		else if (len == 3 && stack_len(*chunks_a) == 1)
			sort_3a(a, instr);
		else if (len == 3)
		{
			sort_3a_nonemptystack(a, b, instr);
			stack_pop(chunks_a);
			(*chunks_a)->num += 3;
		}
		else if (len != 0)
		{
			list = list_from_stack(*a, len);
			sent = midsort(a, b, instr, list, len, 'a', stack_len(*chunks_a));
			free(list);
			if (sent == -1)
				return(-1);
			stack_push(sent, chunks_b);
			(*chunks_a)->num -= sent;
			if ((*chunks_a)->num == 0)
				stack_pop(chunks_a);
		}
		return(sort_stack(a, b, instr, chunks_a, chunks_b));
	}
	else if ((*b) != NULL)
	{
		len = (*chunks_b)->num;
		if (len == 1)
		{
			push(b, a, instr, 'a');
			stack_pop(chunks_b);
		}
		else if (len == 2)
		{
			sort_2(b, 'b', instr);
			push(b, a, instr, 'a');
			push(b, a, instr, 'a');
			stack_pop(chunks_b);
		}
		else if (len == 3 && stack_len(*chunks_b) == 1)
		{
			sort_3b(b, instr);
			push(b, a, instr, 'a');
			push(b, a, instr, 'a');
			push(b, a, instr, 'a');
			stack_pop(chunks_b);
		}
		else if (len == 3)
		{
			sort_3b_nonemptystack(a, b, instr);
			stack_pop(chunks_b);
		}
		else
		{
			list = list_from_stack(*b, len);
			sent = midsort(b, a, instr, list, len, 'b', stack_len(*chunks_b));
			free(list);
			if (sent == -1)
				return(-1);
			if (sent == 0)
			{
				while (len > 0)
				{
					push(b, a, instr, 'a');
					len--;
				}
				stack_pop(chunks_b);
			}
			else
			{
				stack_push(sent, chunks_a);
				(*chunks_b)->num -= sent;
				if ((*chunks_b)->num == 0)
					stack_pop(chunks_b);	
			}
		}
		return(sort_stack(a, b, instr, chunks_a, chunks_b));
	}
	else
		return(1);
	return(0);
}