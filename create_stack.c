/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:28:41 by eshor             #+#    #+#             */
/*   Updated: 2020/07/06 16:38:15 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack_a(int argc, int *argv)
{
	t_stack *stack;

	stack = stack_new(argv[argc - 1]);
	argc = argc - 2;
	while (argc >= 0)
	{
		stack_push(argv[argc], &stack);
		argc--;
	}
	return (stack);
}

int		instr_to_int(char *str)
{
	int		res;
	int		i;

	res = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == 'r')
			res = res * 10 + 1;
		else if (str[i] == 'a')
			res = res * 10 + 2;
		else if (str[i] == 's')
			res = res * 10 + 5;
		else if (str[i] == 'p')
			res = res * 10 + 6;
		else if (str[i] == 'b')
			res = res * 10 + 8;
		else
			return (-1);
	}
	if (res == 52 || res == 58 || res == 55 || res == 62 || res == 68 || res ==
	12 || res == 18 || res == 11 || res == 112 || res == 118 || res == 111)
		return (res);
	else
		return (-1);
}

int		free_str_return(char *str)
{
	ft_strdel(&str);
	return (-1);
}

int		create_instr(int *check, t_stack **a, t_stack **b, int v)
{
	char	*str;
	int		cont;

	while (get_next_line(0, &str))
	{
		*check = 1;
		cont = instr_to_int(str);
		if (cont == -1)
			return (free_str_return(str));
		else
			apply_instr(a, b, cont, v);
		ft_strdel(&str);
	}
	return (0);
}

void	print_instr(t_stack *instr)
{
	t_stack *temp;

	temp = instr;
	while (temp)
	{
		if (temp->num / 100 == 1)
			ft_printf("rr");
		if (temp->num / 10 == 5)
			ft_printf("s");
		else if (temp->num / 10 == 6)
			ft_printf("p");
		else if (temp->num / 10 == 1)
			ft_printf("r");
		if (temp->num % 10 == 2)
			ft_printf("a");
		else if (temp->num % 10 == 8)
			ft_printf("b");
		else if (temp->num % 10 == 1)
			ft_printf("r");
		else if (temp->num % 10 == 5)
			ft_printf("s");
		ft_printf("\n");
		temp = temp->next;
	}
}
