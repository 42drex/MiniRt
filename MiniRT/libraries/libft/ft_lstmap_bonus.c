/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shvalma <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:21:52 by shvalma           #+#    #+#             */
/*   Updated: 2024/10/24 10:21:55 by shvalma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*final;
	t_list	*elem;

	final = NULL;
	while (lst)
	{
		elem = malloc(sizeof(t_list));
		if (!elem)
		{
			ft_lstclear(&final, del);
			return (NULL);
		}
		elem -> content = f(lst ->content);
		elem -> next = NULL;
		ft_lstadd_back(&final, elem);
		lst = lst -> next;
	}
	return (final);
}
