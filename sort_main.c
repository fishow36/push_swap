#include "push_swap.h"

/* -1 -- error */
/* 1 -- finished */
int	sort_stack(t_inf **inf, t_stack **chunks_a, t_stack **chunks_b)
{
	int	*list;
	int len;
	int sent;

	if ((*inf)->a && *chunks_a && is_sorted((*inf)->a, (*chunks_a)->num, 'a') == 0)
	{
		len = (*chunks_a)->num;
		if (len == 1 && stack_len(*chunks_a) > 1)
		{
			stack_pop(chunks_a);
			(*chunks_a)->num++;
		}
		else if (len == 2)
		{
			sort_2(&((*inf)->a), 'a', &((*inf)->instr));
			if (stack_len(*chunks_a) > 1)
			{
				stack_pop(chunks_a);
				(*chunks_a)->num += 2;
			}
		}
		else if (len == 3 && stack_len(*chunks_a) == 1)
			sort_3a(&((*inf)->a), &((*inf)->instr));
		else if (len == 3)
		{
			sort_3a_nonemptystack(&((*inf)->a), &((*inf)->b), &((*inf)->instr));
			stack_pop(chunks_a);
			(*chunks_a)->num += 3;
		}
		else if (len != 0)
		{
			list = list_from_stack((*inf)->a, len);
			(*inf)->stack_name = 'a';
			sent = midsort(inf, list, len, stack_len(*chunks_a));
			free(list);
			if (sent == -1)
				return(-1);
			stack_push(sent, chunks_b);
			(*chunks_a)->num -= sent;
			if ((*chunks_a)->num == 0)
				stack_pop(chunks_a);
		}
		return(sort_stack(inf, chunks_a, chunks_b));
	}
	else if ((*inf)->b != NULL)
	{
		print_stacks((*inf)->a, (*inf)->b);
		len = (*chunks_b)->num;
		if (len == 1)
		{
			push(&((*inf)->b), &((*inf)->a), &((*inf)->instr), 'a');
			stack_pop(chunks_b);
		}
		else if (len == 2)
		{
			sort_2(&((*inf)->b), 'b', &((*inf)->instr));
			push(&((*inf)->b), &((*inf)->a), &((*inf)->instr), 'a');
			push(&((*inf)->b), &((*inf)->a), &((*inf)->instr), 'a');
			stack_pop(chunks_b);
		}
		else if (len == 3 && stack_len(*chunks_b) == 1)
		{
			sort_3b(&((*inf)->b), &((*inf)->instr));
			push(&((*inf)->b), &((*inf)->a), &((*inf)->instr), 'a');
			push(&((*inf)->b), &((*inf)->a), &((*inf)->instr), 'a');
			push(&((*inf)->b), &((*inf)->a), &((*inf)->instr), 'a');
			stack_pop(chunks_b);
		}
		else if (len == 3)
		{
			sort_3b_nonemptystack(&((*inf)->a), &((*inf)->b), &((*inf)->instr));
			stack_pop(chunks_b);
		}
		else
		{
			list = list_from_stack((*inf)->b, len);
			(*inf)->stack_name = 'b';
			sent = midsort(inf, list, len, stack_len(*chunks_b));
			free(list);
			if (sent == -1)
				return(-1);
			if (sent == 0)
			{
				while (len > 0)
				{
					push(&((*inf)->b), &((*inf)->a), &((*inf)->instr), 'a');
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
		return(sort_stack(inf, chunks_a, chunks_b));
	}
	else
		return(1);
	return(0);
}