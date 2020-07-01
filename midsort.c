#include "push_swap.h"

int	midsort_a(t_stack **a, t_stack **b, t_stack **instr, int center, int num_to_send)
{
	t_stack *temp;
	t_stack *temp2;
	int rotate_num;

	rotate_num = 0;
	temp = *a;
	while (temp && temp->num < center)
	{
		num_to_send--;
		push(a, b, instr, 'b');
		temp = *a;
	}
	while (temp->next)
		temp = temp->next;
	while (temp && temp->num < center)
	{
		temp2 = temp->prev;
		reverse_rotate(a, instr, 'a');
		push(a, b, instr, 'b');
		num_to_send--;
		temp = temp2;
	}
	while (num_to_send > 0)
	{
		temp = *a;
		if (temp->num < center)
		{
			num_to_send--;
			push(a, b, instr, 'b');
		}
		else
		{
			rotate(a, instr, 'a');
			rotate_num++;
		}
	}
	return(rotate_num);
}

int midsort_b(t_stack **b, t_stack **a, t_stack **instr, int center, int num_to_send)
{
	t_stack *temp;
	int rotate_num;

	rotate_num = 0;
	temp = *b;
	while (temp && temp->num > center)
	{
		num_to_send--;
		push(b, a, instr, 'a');
		temp = *b;
	}
	while (temp->next)
		temp = temp->next;
	while (temp && temp->num > center)
	{
		reverse_rotate(b, instr, 'b');
		push(b, a, instr, 'a');
		num_to_send--;
		temp = temp->prev;
	}
	while (num_to_send > 0)
	{
		temp = *b;
		if (temp->num > center)
		{
			num_to_send--;
			push(b, a, instr, 'a');
		}
		else
		{
			rotate(b, instr, 'b');
			rotate_num++;
		}
	}
	return(rotate_num);
}

int	midsort(t_stack **from, t_stack **to, t_stack **instr, int *list, int len, char stack_name, int num_chunks_in_from)
{
	int *for_sort;
	int center;
	int num_to_send;
	int rotate_num;


	if (is_sorted(*from, len, stack_name) == 1)
		return (0);
	for_sort = bubble_sort(list, len);
	center = len / 2;
	num_to_send = (len % 2 == 0 && stack_name == 'a') ?
	len - center : len - center - 1;
	if (stack_name == 'a')
		rotate_num = midsort_a(from, to, instr, for_sort[center], num_to_send);
	else
		rotate_num = midsort_b(from, to, instr, for_sort[center], num_to_send);
	if (num_chunks_in_from != 1)
	{
		while (rotate_num > 0)
		{
			reverse_rotate(from, instr, stack_name);
			rotate_num--;
		}
	}
	return(num_to_send);
}