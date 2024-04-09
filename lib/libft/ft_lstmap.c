/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:04:09 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/10 16:27:50 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*n;

	new = NULL;
	n = NULL;
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst != NULL)
	{
		n = malloc(sizeof(t_list));
		if (n == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		n->content = f(lst->content);
		n->next = NULL;
		ft_lstadd_back(&new, n);
		lst = lst->next;
	}
	return (new);
}
