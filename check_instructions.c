/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:28:36 by eshor             #+#    #+#             */
/*   Updated: 2020/07/06 16:33:35 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_instr2(t_stack **a, t_stack **b, int num)
{
	t_stack *fill;

	fill = NULL;
	if (num == 11)
	{
		rotate(a, &fill, 'a');
		rotate(b, &fill, 'b');
	}
	else if (num == 112)
		reverse_rotate(a, &fill, 'a');
	else if (num == 118)
		reverse_rotate(b, &fill, 'b');
	else if (num == 12)
		rotate(a, &fill, 'a');
	else if (num == 18)
		rotate(b, &fill, 'b');
	else
	{
		reverse_rotate(a, &fill, 'a');
		reverse_rotate(b, &fill, 'b');
	}
	stack_free(&fill);
}

void	apply_instr(t_stack **a, t_stack **b, int num, int v)
{
	t_stack *fill;

	fill = NULL;
	if (num == 52)
		swap(a, &fill, 'a');
	else if (num == 58)
		swap(b, &fill, 'b');
	else if (num == 55)
	{
		swap(a, &fill, 'a');
		swap(b, &fill, 'b');
	}
	else if (num == 62)
		push(b, a, &fill, 'a');
	else if (num == 68)
		push(a, b, &fill, 'b');
	else
		apply_instr2(a, b, num);
	if (v == 1)
		print_stacks(*a, *b);
	stack_free(&fill);
}

void	free_main(t_stack **a, t_stack **b)
{
	stack_free(a);
	stack_free(b);
}

void	check_instr(int *list, int len, int v)
{
	t_stack		*a;
	t_stack		*b;
	int			instr;
	int			check;

	a = create_stack_a(len, list);
	free(list);
	b = NULL;
	check = 0;
	if (v == 1)
		print_stacks(a, b);
	instr = create_instr(&check, &a, &b, v);
	if ((instr == -1 && check == 1) || !a)
	{
		ft_printf("Error\n");
		free_main(&a, &b);
		return ;
	}
	if (is_sorted(a, stack_len(a), 'a') == 1 && b == NULL)
		ft_printf("%s\n", "OK");
	else
		ft_printf("%s\n", "KO");
	free_main(&a, &b);
}
