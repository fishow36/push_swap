/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:02:36 by eshor             #+#    #+#             */
/*   Updated: 2019/09/26 19:51:41 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*res;
	char	*ptr;
	char	*ptr2;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	ptr = (char*)s;
	ptr2 = res;
	while (*ptr)
	{
		*ptr2 = f(*ptr);
		ptr++;
		ptr2++;
	}
	return (res);
}
