/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:51:55 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/13 00:17:58 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr_private.h"

t_list	*strb_new_node(char *str, t_del del)
{
	t_substr	*substr;
	t_list		*node;

	if (str == NULL)
		return (NULL);
	substr = strb_create_substr(str, ft_strlen(str), del);
	if (substr == NULL)
		return (NULL);
	node = ft_lstnew(substr);
	if (node == NULL)
	{
		free(substr);
		return (NULL);
	}
	return (node);
}
