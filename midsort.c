/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:28:47 by eshor             #+#    #+#             */
/*   Updated: 2020/07/06 14:47:36 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	traverse_rest(t_inf **inf, int center, int num_to_send, int rotate_num)
{
	t_stack *temp;

	while (num_to_send > 0)
	{
		temp = ((*inf)->stack_name == 'a') ? (*inf)->a : (*inf)->b;
		if (((*inf)->stack_name == 'a' && temp->num < center) ||
		((*inf)->stack_name == 'b' && temp->num > center))
		{
			num_to_send--;
			if ((*inf)->stack_name == 'a')
				push(&((*inf)->a), &((*inf)->b), &((*inf)->instr), 'b');
			else
				push(&((*inf)->b), &((*inf)->a), &((*inf)->instr), 'a');
		}
		else
		{
			if ((*inf)->stack_name == 'a')
				rotate(&((*inf)->a), &((*inf)->instr), 'a');
			else
				rotate(&((*inf)->b), &((*inf)->instr), 'b');
			rotate_num++;
		}
	}
	return (rotate_num);
}

int	midsort_a(t_inf **inf, int center, int num_to_send)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		rotate_num;

	rotate_num = 0;
	temp = (*inf)->a;
	while (temp && temp->num < center)
	{
		num_to_send--;
		push(&((*inf)->a), &((*inf)->b), &((*inf)->instr), 'b');
		temp = (*inf)->a;
	}
	while (temp->next)
		temp = temp->next;
	while (temp && temp->num < center)
	{
		temp2 = temp->prev;
		reverse_rotate(&((*inf)->a), &((*inf)->instr), 'a');
		push(&((*inf)->a), &((*inf)->b), &((*inf)->instr), 'b');
		num_to_send--;
		temp = temp2;
	}
	rotate_num = traverse_rest(inf, center, num_to_send, rotate_num);
	return (rotate_num);
}

int	midsort_b(t_inf **inf, int center, int num_to_send)
{
	t_stack	*temp;
	int		rotate_num;

	rotate_num = 0;
	temp = (*inf)->b;
	while (temp && temp->num > center)
	{
		num_to_send--;
		push(&((*inf)->b), &((*inf)->a), &((*inf)->instr), 'a');
		temp = (*inf)->b;
	}
	while (temp->next)
		temp = temp->next;
	while (temp && temp->num > center)
	{
		reverse_rotate(&((*inf)->b), &((*inf)->instr), 'b');
		push(&((*inf)->b), &((*inf)->a), &((*inf)->instr), 'a');
		num_to_send--;
		temp = temp->prev;
	}
	rotate_num = traverse_rest(inf, center, num_to_send, rotate_num);
	return (rotate_num);
}

/*
** stack_name -- тот, который сортируем (= from)
*/

int	midsort(t_inf **inf, int *list, int len, int num_chunks_in_from)
{
	int		*for_sort;
	int		num_to_send;
	int		rotate_num;
	t_stack	**from;

	from = ((*inf)->stack_name == 'a') ? &((*inf)->a) : &((*inf)->b);
	if (is_sorted(*from, len, (*inf)->stack_name) == 1)
		return (0);
	for_sort = bubble_sort(list, len);
	num_to_send = (len % 2 == 0 && (*inf)->stack_name == 'a') ?
	len - (len / 2) : len - (len / 2) - 1;
	if ((*inf)->stack_name == 'a')
		rotate_num = midsort_a(inf, for_sort[len / 2], num_to_send);
	else
		rotate_num = midsort_b(inf, for_sort[len / 2], num_to_send);
	if (num_chunks_in_from != 1)
	{
		while (rotate_num-- > 0)
			reverse_rotate(from, &((*inf)->instr), (*inf)->stack_name);
	}
	return (num_to_send);
}
