/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 12:59:22 by eshor             #+#    #+#             */
/*   Updated: 2019/09/24 20:21:05 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;
	size_t			i;

	ptr_d = (unsigned char*)dest;
	ptr_s = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ptr_d[i] = ptr_s[i];
		if (ptr_s[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
