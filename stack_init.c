/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:29:10 by eshor             #+#    #+#             */
/*   Updated: 2020/07/06 14:44:36 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*find_instr(int *list, int len)
{
	t_stack *a;
	t_stack *b;
	t_stack	*instr;

	a = create_stack_a(len, list);
	b = NULL;
	instr = NULL;
	stack_free(&a);
	stack_free(&b);
	return (instr);
}
