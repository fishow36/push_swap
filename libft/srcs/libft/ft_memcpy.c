/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:28:45 by eshor             #+#    #+#             */
/*   Updated: 2019/09/25 19:28:46 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;

	if (dest == NULL && src == NULL)
		return (0);
	ptr = (unsigned char*)dest;
	ptr2 = (unsigned char*)src;
	while (n > 0)
	{
		*ptr = *ptr2;
		ptr++;
		ptr2++;
		n--;
	}
	return (dest);
}
