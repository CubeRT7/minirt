/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_delete_substr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:58:32 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/13 00:49:57 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr_private.h"

void	strb_delete_substr(void *p)
{
	t_substr	*substr;

	substr = p;
	if (substr == NULL)
		return ;
	strb_delete_str(substr->str, substr->del);
	free(substr);
}
