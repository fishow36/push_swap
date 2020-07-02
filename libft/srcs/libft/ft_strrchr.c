/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:29:59 by eshor             #+#    #+#             */
/*   Updated: 2019/09/24 19:31:34 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char*)&s[ft_strlen(s)]);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char*)&s[len]);
		len--;
	}
	return (NULL);
}
