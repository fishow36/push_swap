/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:03:57 by eshor             #+#    #+#             */
/*   Updated: 2019/09/26 19:29:49 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = 0;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	while (*s == ' ' || *s == '\t' || *s == '\n')
	{
		s++;
		len--;
	}
	if (len <= 0)
		return (ft_strnew(1));
	result = (char*)malloc(sizeof(char) * (len + 2));
	if (!result)
		return (NULL);
	while (i < len + 1)
		result[i++] = *s++;
	result[i] = '\0';
	return (result);
}
