/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:29:04 by eshor             #+#    #+#             */
/*   Updated: 2020/07/06 15:06:16 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int cont)
{
	t_stack *res;

	res = (t_stack*)malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->num = cont;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

void	stack_push(int cont, t_stack **stack)
{
	t_stack *new;

	new = stack_new(cont);
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

void	stack_push_back(int cont, t_stack **stack)
{
	t_stack *new;
	t_stack *temp;

	new = stack_new(cont);
	if (*stack != NULL)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	else
		*stack = new;
}

int		stack_pop(t_stack **stack)
{
	int		cont;
	t_stack	*to_free;

	cont = -1;
	if (*stack)
	{
		cont = (*stack)->num;
		to_free = *stack;
		*stack = (*stack)->next;
		free(to_free);
	}
	return (cont);
}

void	stack_free(t_stack **stack)
{
	t_stack *temp;

	while (*stack)
	{
		temp = (*stack)->next;
		stack_pop(stack);
		*stack = temp;
	}
}
