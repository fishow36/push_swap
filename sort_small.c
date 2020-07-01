#include "push_swap.h"

void	sort_2(t_stack **stack, char stack_name, t_stack **instr)
{
	if (((*stack)->num > (*stack)->next->num && stack_name == 'a')
	|| ((*stack)->num < (*stack)->next->num && stack_name == 'b'))
	{
		swap(stack, instr, stack_name);
	}
}

/* Only for when these 3 numbers are the only elements in the stack*/
void sort_3a(t_stack **stack, t_stack **instr)
{
	if ((*stack)->num > (*stack)->next->num &&
	(*stack)->next->num > (*stack)->next->next->num)
	{
		rotate(stack, instr, 'a');
		swap(stack, instr, 'a');
	}
	else if ((*stack)->num > (*stack)->next->next->num &&
	(*stack)->next->num < (*stack)->next->next->num)
		rotate(stack, instr, 'a');
	else if ((*stack)->num > (*stack)->next->num &&
	(*stack)->num < (*stack)->next->next->num)
		swap(stack, instr, 'a');
	else if ((*stack)->num < (*stack)->next->num &&
	(*stack)->num > (*stack)->next->next->num)
		reverse_rotate(stack, instr, 'a');
	else if ((*stack)->num < (*stack)->next->next->num &&
	(*stack)->next->num > (*stack)->next->next->num)
	{
		reverse_rotate(stack, instr, 'a');
		swap(stack, instr, 'a');
	}
}

void sort_3b(t_stack **stack, t_stack **instr)
{
	if ((*stack)->num > (*stack)->next->next->num &&
	(*stack)->next->num < (*stack)->next->next->num)
	{
		reverse_rotate(stack, instr, 'b');
		swap(stack, instr, 'b');
	}
	else if ((*stack)->num > (*stack)->next->num &&
	(*stack)->num < (*stack)->next->next->num)
		reverse_rotate(stack, instr, 'b');
	else if ((*stack)->num < (*stack)->next->num &&
	(*stack)->num > (*stack)->next->next->num)
		swap(stack, instr, 'b');
	else if ((*stack)->num < (*stack)->next->num &&
	(*stack)->next->num < (*stack)->next->next->num)
	{
		swap(stack, instr, 'b');
		reverse_rotate(stack, instr, 'b');
	}
	else if ((*stack)->num < (*stack)->next->next->num &&
	(*stack)->next->num > (*stack)->next->next->num)
		rotate(stack, instr, 'b');
}

void	sort_3a_nonemptystack(t_stack **a, t_stack **b, t_stack **instr)
{
	if ((*a)->num > (*a)->next->num && (*a)->next->num > (*a)->next->next->num)
	{
		rotate(a, instr, 'a');
		rotate(a, instr, 'a');
		push(a, b, instr, 'b');
		reverse_rotate(a, instr, 'a');
		reverse_rotate(a, instr, 'a');
		swap(a, instr, 'a');
		push(b, a, instr, 'a');
	}
	else if ((*a)->num > (*a)->next->next->num 
	&& (*a)->next->num < (*a)->next->next->num)
	{
		rotate(a, instr, 'a');
		push(a, b, instr, 'b');
		reverse_rotate(a, instr, 'a');
		swap(a, instr, 'a');
		push(b, a, instr, 'a');
	}
	else if ((*a)->num > (*a)->next->num &&
	(*a)->num < (*a)->next->next->num)
		swap(a, instr, 'a');
	else if ((*a)->num < (*a)->next->num &&
	(*a)->num > (*a)->next->next->num)
	{
		rotate(a, instr, 'a');
		swap(a, instr, 'a');
		reverse_rotate(a, instr, 'a');
	}
	else if ((*a)->num < (*a)->next->next->num &&
	(*a)->next->num > (*a)->next->next->num)
	{
		push(a, b, instr, 'b');
		swap(a, instr, 'a');
		push(b, a, instr, 'a');
	}
}

void	sort_3b_nonemptystack(t_stack **a, t_stack **b, t_stack **instr)
{
	// ft_printf("sort 3\n");
	if ((*b)->num < (*b)->next->num &&
	(*b)->next->num < (*b)->next->next->num)
	{
		rotate(b, instr, 'b');
		swap(b, instr, 'b');
		push(b, a, instr, 'a');
		push(b, a, instr, 'a');
		reverse_rotate(b, instr, 'b');
		push(b, a, instr, 'a');
	}
	else if ((*b)->num > (*b)->next->num && (*b)->num < (*b)->next->next->num)
	{
		rotate(b, instr, 'b');
		swap(b, instr, 'b');
		push(b, a, instr, 'a');
		reverse_rotate(b, instr, 'b');
		push(b, a, instr, 'a');
		push(b, a, instr, 'a');
	}
	else if ((*b)->num < (*b)->next->next->num && (*b)->next->num > (*b)->next->next->num)
	{
		rotate(b, instr, 'b');
		push(b, a, instr, 'a');
		push(b, a, instr, 'a');
		reverse_rotate(b, instr, 'b');
		push(b, a, instr, 'a');
	}
	else if ((*b)->num < (*b)->next->num && (*b)->num > (*b)->next->next->num)
	{
		rotate(b, instr, 'b');
		push(b, a, instr, 'a');
		reverse_rotate(b, instr, 'b');
		push(b, a, instr, 'a');
		push(b, a, instr, 'a');
	}
	else if ((*b)->num > (*b)->next->next->num && (*b)->next->num < (*b)->next->next->num)
	{
		push(b, a, instr, 'a');
		swap(b, instr, 'b');
		push(b, a, instr, 'a');
		push(b, a, instr, 'a');
	}
	else
	{
		push(b, a, instr, 'a');
		push(b, a, instr, 'a');
		push(b, a, instr, 'a');
	}
	
	// ft_printf("sort3 finished\n");
	// print_stack(*a);
	// print_stack(*b);
}