/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:50:59 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 23:38:11 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr_private.h"

int	strb_init(t_strb *sb, char *str, t_del del)
{
	sb->substrs = 0;
	sb->last = 0;
	sb->len = 0;
	sb->err = STRB_SUCCESS;
	if (str == NULL)
		return (STRB_SUCCESS);
	return (strb_add_left(sb, str, del));
}
