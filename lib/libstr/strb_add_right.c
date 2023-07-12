/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_add_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:02 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/13 01:05:01 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr_private.h"

int	strb_add_right(t_strb *sb, char *str, t_del del)
{
	t_list	*node;

	if (sb->err || str == NULL)
	{
		strb_delete_str(str, del);
		return (STRB_FAIL);
	}
	if (*str == '\0')
	{
		strb_delete_str(str, del);
		return (STRB_SUCCESS);
	}
	node = strb_new_node(str, del);
	if (node == NULL)
		return (strb_fail_clear(sb, str, del));
	ft_lstadd_back(&(sb->substrs), node);
	sb->len += ((t_substr *)node->content)->len;
	if (sb->substrs == node)
		sb->last = node;
	return (STRB_SUCCESS);
}
