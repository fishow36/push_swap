/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:03:45 by eshor             #+#    #+#             */
/*   Updated: 2019/09/25 22:33:28 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!res)
		return (NULL);
	else
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		while (*s2)
		{
			res[i++] = *s2++;
		}
		res[i] = '\0';
		return (res);
	}
}
