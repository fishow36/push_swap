/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:02:06 by eshor             #+#    #+#             */
/*   Updated: 2019/09/26 20:13:36 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	char *ptr;

	if (!s || !f)
		return ;
	ptr = s;
	while (*ptr)
	{
		(*f)(ptr);
		ptr++;
	}
}
