#include "push_swap.h"

void	replace_swaps(t_stack **instr)
{
	t_stack *temp;

	temp = *instr;
	while (temp && temp->next)
	{
		if ((temp->num == 52 && temp->next->num == 58) ||
		temp->num == 58 && temp->next->num == 52)
		{
			temp->num = 55;
			temp->next = temp->next->next;
		}
		temp = temp->next;
	}
}

void	replace_rotates(t_stack **instr)
{
	t_stack *temp;
	t_stack *temp2;

	temp = *instr;
	while (temp && temp->next)
	{
		if ((temp->num == 12 && temp->next->num == 18) ||
		temp->num == 18 && temp->next->num == 12)
		{
			temp->num = 11;
			temp2 = temp->next->next;
			free(temp->next);
			temp->next = temp2;
		}
		else if ((temp->num == 112 && temp->next->num == 118) ||
		temp->num == 118 && temp->next->num == 112)
		{
			temp->num = 111;
			temp2 = temp->next->next;
			free(temp->next);
			temp->next = temp2;
		}
		temp = temp->next;
	}
}

void	replace_pushes(t_stack **instr)
{
	t_stack *temp;
	t_stack *temp2;

	temp = *instr;
	while (temp)
	{
		if (temp->next &&  temp->next->next &&
		((temp->next->num == 62 && temp->next->next->num == 68)
		|| (temp->next->num == 68 && temp->next->next->num == 62)))
		{
			temp2 = temp->next;
			temp->next = temp->next->next->next;
			free(temp2->next);
			free(temp2);
			if (temp->prev)
			{
				temp = temp->prev;
				if (temp->prev)
					temp = temp->prev;
			}
		}
		temp = temp->next;
	}
}

void	replace_pushswap(t_stack **instr)
{
	t_stack *temp;
	t_stack *temp2;

	temp = *instr;
	while (temp)
	{
		if (temp->next && temp->next->next && temp->next->next->next &&
		temp->next->next->next->next && temp->num == 68 && temp->next->num == 68
		&& temp->next->next->num == 58 && temp->next->next->next->num == 62
		&& temp->next->next->next->next->num == 62)
		{
			temp->num = 52;
			temp2 = temp->next->next->next->next->next;
			free(temp->next);
			free(temp->next->next);
			free(temp->next->next->next);
			free(temp->next->next->next->next);
			temp->next = temp2;
		}
		temp = temp->next;
	}
}

void	replace_r_rr(t_stack **instr)
{
	t_stack *temp;
	t_stack *temp2;

	temp = *instr;
	while (temp)
	{
		if (temp->next &&  temp->next->next &&
		((temp->next->num == 118 && temp->next->next->num == 18)
		|| (temp->next->num == 18 && temp->next->next->num == 118)
		|| (temp->next->num == 12 && temp->next->next->num == 112)
		|| (temp->next->num == 112 && temp->next->next->num == 12)))
		{
			temp2 = temp->next;
			temp->next = temp->next->next->next;
			free(temp2->next);
			free(temp2);
			if (temp->prev)
			{
				temp = temp->prev;
				if (temp->prev)
					temp = temp->prev;
			}
		}
		temp = temp->next;
	}
}