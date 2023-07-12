/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_fail_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:10:15 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/13 01:03:25 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr_private.h"

int	strb_fail_clear(t_strb *sb, char *str, t_del del)
{
	sb->err = STRB_FAIL;
	strb_delete_str(str, del);
	strb_clear(sb);
	return (STRB_FAIL);
}
