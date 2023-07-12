/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstr_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:36:48 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/13 01:02:28 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTR_PRIVATE_H
# define LIBSTR_PRIVATE_H
# include <stdlib.h>
# include "libstr.h"

typedef struct s_substr
{
	t_del	del;
	char	*str;
	int		len;
}	t_substr;

char		*strb_build(t_strb *sb);
void		strb_clear(t_strb *sb);
t_list		*strb_new_node(char *str, t_del del);
t_substr	*strb_create_substr(char *str, int len, t_del del);
void		strb_delete_substr(void *substr);
void		strb_delete_str(char *str, t_del del);
int			strb_fail_clear(t_strb *sb, char *str, t_del del);

#endif
