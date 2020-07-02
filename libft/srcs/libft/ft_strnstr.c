/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 12:26:53 by eshor             #+#    #+#             */
/*   Updated: 2019/09/24 20:11:18 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t b;
	size_t l;

	b = 0;
	if (!*little)
		return ((char*)big);
	else
	{
		while (b < len && big[b])
		{
			if (big[b] == little[0])
			{
				l = 1;
				while (little[l] && big[b + l] && b + l < len &&
				big[b + l] == little[l])
					l++;
				if (little[l] == '\0')
					return ((char*)&big[b]);
			}
			b++;
		}
		return (NULL);
	}
}
