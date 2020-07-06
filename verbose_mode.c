/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:29:21 by eshor             #+#    #+#             */
/*   Updated: 2020/07/06 14:38:07 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** в инте макс. 11 знаков -- поля по 11
*/

void	print_next(t_stack **stack)
{
	if (*stack)
	{
		ft_printf("%11d ", (*stack)->num);
		*stack = (*stack)->next;
	}
	else
		ft_printf("            ");
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int			len;
	int			i;
	t_stack		*temp_a;
	t_stack		*temp_b;

	if (stack_len(a) > stack_len(b))
		len = stack_len(a);
	else
		len = stack_len(b);
	temp_a = a;
	temp_b = b;
	i = 0;
	ft_printf("******A*************B******\n");
	while (i < len)
	{
		ft_printf("*");
		print_next(&temp_a);
		ft_printf("*");
		print_next(&temp_b);
		ft_printf("*\n");
		i++;
	}
	ft_printf("***************************\n\n");
}
