/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:53:35 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/09 14:22:10 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;
	t_list	*new;

	head = NULL;
	tail = NULL;
	while (lst && f)
	{
		new = ft_lstnew(NULL);
		if (new == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new->content = f(lst->content);
		if (tail == NULL)
			head = new;
		else
			tail->next = new;
		tail = new;
		lst = lst->next;
	}
	return (head);
}
