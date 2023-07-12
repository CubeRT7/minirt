/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:53:04 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 23:53:53 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr_private.h"

void	strb_clear(t_strb *sb)
{
	ft_lstclear(&(sb->substrs), strb_delete_substr);
	strb_init(sb, NULL, NULL);
}
