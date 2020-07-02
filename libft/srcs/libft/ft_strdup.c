/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:29:28 by eshor             #+#    #+#             */
/*   Updated: 2019/09/22 11:29:29 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		i;

	i = 0;
	while (s[i])
		i++;
	result = (char*)malloc(sizeof(char) * (i + 1));
	if (result)
	{
		i = 0;
		while (s[i])
		{
			result[i] = s[i];
			i++;
		}
		result[i] = '\0';
		return (result);
	}
	else
		return (NULL);
}
