/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:43 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/13 00:39:01 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr_private.h"

char	*strb_build(t_strb *sb)
{
	char		*res;
	char		*str;
	t_list		*lst;
	int			idx;

	if (sb->err)
		return (NULL);
	res = (char *)malloc(sb->len + 1);
	if (res == NULL)
	{
		strb_fail_clear(sb, NULL, NULL);
		return (NULL);
	}
	lst = sb->substrs;
	idx = 0;
	while (lst)
	{
		str = ((t_substr *)lst->content)->str;
		while (*str)
			res[idx++] = *str++;
		lst = lst->next;
	}
	res[idx] = 0;
	return (res);
}
