/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:29:00 by eshor             #+#    #+#             */
/*   Updated: 2020/07/06 14:48:17 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack, char stack_name, t_stack **instr)
{
	if (((*stack)->num > (*stack)->next->num && stack_name == 'a')
	|| ((*stack)->num < (*stack)->next->num && stack_name == 'b'))
	{
		swap(stack, instr, stack_name);
	}
}

/*
** Only for when these 3 numbers are the only elements in the stack
*/

void	sort_3a(t_stack **stack, t_stack **instr)
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

void	sort_3b(t_stack **stack, t_stack **instr)
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
