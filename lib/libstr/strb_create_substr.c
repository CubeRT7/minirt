/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_create_substr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:49:48 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/13 00:19:12 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr_private.h"

t_substr	*strb_create_substr(char *str, int len, t_del del)
{
	t_substr	*substr;

	if (str == NULL)
		return (NULL);
	substr = (t_substr *)malloc(sizeof(t_substr));
	if (substr == NULL)
		return (NULL);
	substr->str = str;
	substr->len = len;
	if (len == DETECT_LEN)
		substr->len = ft_strlen(str);
	substr->del = del;
	return (substr);
}
