/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:10:07 by eshor             #+#    #+#             */
/*   Updated: 2019/09/26 19:10:08 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *maplist;
	t_list *temp;

	if (!lst)
		return (NULL);
	maplist = f(lst);
	temp = maplist;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = f(lst);
		if (!(temp->next))
		{
			free(temp->next);
			return (NULL);
		}
		temp = temp->next;
	}
	return (maplist);
}
