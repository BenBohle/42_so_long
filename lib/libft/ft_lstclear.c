/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:44:15 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/10 15:56:41 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*new;

	tmp = *lst;
	new = NULL;
	if (lst == NULL)
	{
		return ;
	}
	while (tmp != NULL)
	{
		new = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = new;
	}
	*lst = NULL;
}
