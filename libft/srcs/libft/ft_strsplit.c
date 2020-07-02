/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:04:06 by eshor             #+#    #+#             */
/*   Updated: 2019/09/28 12:27:23 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char		**clear_tab(int i, char ***tab)
{
	while (tab[i])
	{
		free(tab[i]);
		i--;
	}
	return (NULL);
}

static char		**ft_filltab(char **tab, char const *s, char c, int count_words)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0' && i < (int)ft_strlen(s))
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			count_words++;
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			tab[count_words] = ft_strnew(j + 1);
			if (!tab[count_words])
				return (clear_tab(count_words, &tab));
			j = 0;
			while (s[i] && s[i] != c)
			{
				tab[count_words][j++] = s[i++];
			}
		}
		i++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		count_words;

	if (!s)
		return (NULL);
	count_words = ft_count_words(s, c);
	tab = (char**)malloc(sizeof(char*) * (count_words + 1));
	if (!tab)
		return (NULL);
	tab[count_words] = 0;
	tab = ft_filltab(tab, s, c, -1);
	return (tab);
}
