/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:00:43 by eshor             #+#    #+#             */
/*   Updated: 2019/09/26 21:19:54 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *freshmem;

	if (size == 0)
		return (NULL);
	freshmem = malloc(size);
	if (!freshmem)
		return (NULL);
	else
	{
		ft_bzero(freshmem, size);
		return (freshmem);
	}
}
