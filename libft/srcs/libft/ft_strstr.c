/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:30:03 by eshor             #+#    #+#             */
/*   Updated: 2019/09/25 20:02:15 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		h;
	int		n;
	char	*ptr_h;
	char	*ptr_n;

	if (!*needle)
		return ((char*)haystack);
	ptr_h = (char*)haystack;
	ptr_n = (char*)needle;
	h = 0;
	while (ptr_h[h] != '\0')
	{
		if (ptr_h[h] == ptr_n[0])
		{
			n = 0;
			while (ptr_n[n] != '\0' && ptr_h[h + n] == ptr_n[n])
				n++;
			if (ptr_n[n] == '\0')
				return ((char*)&ptr_h[h]);
		}
		h++;
	}
	return (NULL);
}
