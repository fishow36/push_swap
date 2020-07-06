/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_nonempty.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:31:45 by eshor             #+#    #+#             */
/*   Updated: 2020/07/06 14:44:06 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3a_continue(t_stack **a, t_stack **b, t_stack **instr)
{
	if ((*a)->num > (*a)->next->num &&
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
	else
		sort_3a_continue(a, b, instr);
}

void	sort_3b_continue2(t_stack **a, t_stack **b, t_stack **instr)
{
	if ((*b)->num > (*b)->next->next->num &&
	(*b)->next->num < (*b)->next->next->num)
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
}

void	sort_3b_continue(t_stack **a, t_stack **b, t_stack **instr)
{
	if ((*b)->num < (*b)->next->next->num &&
	(*b)->next->num > (*b)->next->next->num)
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
	else
		sort_3b_continue2(a, b, instr);
}

void	sort_3b_nonemptystack(t_stack **a, t_stack **b, t_stack **instr)
{
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
	else
		sort_3b_continue(a, b, instr);
}
