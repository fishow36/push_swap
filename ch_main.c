/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:06:52 by eshor             #+#    #+#             */
/*   Updated: 2020/07/06 15:07:04 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*int_list;
	int		v;

	if (argc == 1)
		return (0);
	v = 0;
	if (ft_strcmp(argv[1], "-v") == 0)
		v = 1;
	if ((int_list = list_validation(argc, argv, v)) == NULL)
	{
		ft_printf("%s\n", "Error");
		return (0);
	}
	check_instr(int_list, argc - (v + 1), v);
	return (0);
}
