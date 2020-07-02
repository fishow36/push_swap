/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:03:32 by eshor             #+#    #+#             */
/*   Updated: 2019/09/26 20:11:06 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	res = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!res || !s)
		return (NULL);
	else
	{
		while (i < len)
		{
			res[i] = s[start];
			i++;
			start++;
		}
		res[i] = '\0';
		return (res);
	}
}
