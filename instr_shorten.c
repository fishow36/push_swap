/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_shorten.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:28:44 by eshor             #+#    #+#             */
/*   Updated: 2020/07/06 14:45:03 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_swaps(t_stack **instr)
{
	t_stack *tmp;
	t_stack *tmp2;

	tmp = *instr;
	while (tmp && tmp->next)
	{
		if ((tmp->num == 52 && tmp->next->num == 58) ||
		(tmp->num == 58 && tmp->next->num == 52))
		{
			tmp->num = 55;
			free(tmp->next);
			tmp2 = tmp->next->next;
			tmp->next = tmp2;
		}
		tmp = tmp->next;
	}
}

void	replace_rotates(t_stack **instr)
{
	t_stack *tmp;
	t_stack *tmp2;

	tmp = *instr;
	while (tmp && tmp->next)
	{
		if ((tmp->num == 12 && tmp->next->num == 18) ||
		(tmp->num == 18 && tmp->next->num == 12))
		{
			tmp->num = 11;
			tmp2 = tmp->next->next;
			free(tmp->next);
			tmp->next = tmp2;
		}
		else if ((tmp->num == 112 && tmp->next->num == 118) ||
		(tmp->num == 118 && tmp->next->num == 112))
		{
			tmp->num = 111;
			tmp2 = tmp->next->next;
			free(tmp->next);
			tmp->next = tmp2;
		}
		tmp = tmp->next;
	}
}

void	replace_pushes(t_stack **instr)
{
	t_stack *tmp;
	t_stack *tmp2;

	tmp = *instr;
	while (tmp)
	{
		if (tmp->next && tmp->next->next &&
		((tmp->next->num == 62 && tmp->next->next->num == 68)
		|| (tmp->next->num == 68 && tmp->next->next->num == 62)))
		{
			tmp2 = tmp->next;
			tmp->next = tmp->next->next->next;
			free(tmp2->next);
			free(tmp2);
			if (tmp->prev)
			{
				tmp = tmp->prev;
				if (tmp->prev)
					tmp = tmp->prev;
			}
		}
		tmp = tmp->next;
	}
}

void	replace_pushswap(t_stack **instr)
{
	t_stack *tmp;
	t_stack *tmp2;

	tmp = *instr;
	while (tmp)
	{
		if (tmp && tmp->next && tmp->next->next && tmp->next->next->next &&
		tmp->next->next->next->next && tmp->num == 68 && tmp->next->num == 68
		&& tmp->next->next->num == 58 && tmp->next->next->next->num == 62
		&& tmp->next->next->next->next->num == 62)
		{
			tmp->num = 52;
			tmp2 = tmp->next->next->next->next->next;
			free(tmp->next->next->next->next);
			free(tmp->next->next->next);
			free(tmp->next->next);
			free(tmp->next);
			tmp->next = tmp2;
		}
		tmp = tmp->next;
	}
}

void	replace_r_rr(t_stack **instr)
{
	t_stack *tmp;
	t_stack *tmp2;

	tmp = *instr;
	while (tmp)
	{
		if (tmp && tmp->next && tmp->next->next && tmp->next->next->next &&
		((tmp->next->num == 118 && tmp->next->next->num == 18)
		|| (tmp->next->num == 18 && tmp->next->next->num == 118)
		|| (tmp->next->num == 12 && tmp->next->next->num == 112)
		|| (tmp->next->num == 112 && tmp->next->next->num == 12)))
		{
			tmp2 = tmp->next;
			tmp->next = tmp->next->next->next;
			tmp->next->prev = tmp;
			free(tmp2->next);
			free(tmp2);
			if (tmp && tmp->prev)
				tmp = tmp->prev;
		}
		else
			tmp = tmp->next;
	}
}
