/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:55:21 by eshor             #+#    #+#             */
/*   Updated: 2019/09/24 19:21:45 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t s;
	size_t d;
	size_t result;

	s = 0;
	d = 0;
	result = 0;
	while (dst[d])
		d++;
	while (src[result])
		result++;
	if (size <= d)
		result += size;
	else
		result += d;
	if (size != 0)
	{
		while (src[s] && d < size - 1)
		{
			dst[d++] = src[s++];
		}
		dst[d] = '\0';
	}
	return (result);
}
