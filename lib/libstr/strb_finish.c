/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_finish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:58 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/13 00:00:10 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr_private.h"

char	*strb_finish(struct s_strb *sb)
{
	char	*res;

	if (sb->err)
		return (NULL);
	res = strb_build(sb);
	strb_clear(sb);
	return (res);
}
