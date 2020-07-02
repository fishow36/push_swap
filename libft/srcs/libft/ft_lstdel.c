/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:09:54 by eshor             #+#    #+#             */
/*   Updated: 2019/09/26 19:09:55 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *alst;
	while (ptr)
	{
		temp = ptr;
		ft_lstdelone(&ptr, del);
		ptr = temp->next;
	}
	*alst = NULL;
}
